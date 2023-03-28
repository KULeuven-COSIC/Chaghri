/** Test_CHAGHRI.cpp - test program for homomorphic Chaghri using HElib
 */
#if defined(__unix__) || defined(__unix) || defined(unix)
#include <sys/time.h>
#include <sys/resource.h>
#endif
namespace std {} using namespace std;
namespace NTL {} using namespace NTL;
namespace helib {} using namespace helib;
#include <cstring>
#include "chaghri.h"
#include "helib/Ctxt.h"
#include "helib/ArgMap.h"


static long mValues[][17] = {
//{ p, phi(m),  m,   d, m1, m2, m3,   g1,    g2,   g3,ord1,ord2,ord3, c_m}
  { 2, 47628, 48133, 378,127, 379,0,47755,24258,0,126,-1,0,100,0,0,0},
};

extern void chaghri_schedule(Vec<GF2X> key,GF2X final_keys[]); 

int main(int argc, char **argv)
{
  ArgMap amap;

  long idx = 0;

  long c=3;
  amap.arg("c", c, "number of columns in the key-switching matrices");

  long N=700;
  amap.arg("N", N, "# of bits of the modulus chain");

  long B=23;
  amap.arg("B", B, "# of bits per level (only 64-bit machines)");

  bool boot=false;

  bool packed=true;

  long n_slots = 3;

  long slot_size = 63;

  long n_round = 8;

  amap.parse(argc, argv);


  Vec<long> mvec;
  vector<long> gens;
  vector<long> ords;

  long p = mValues[idx][0];
  long m = mValues[idx][2];

  append(mvec, mValues[idx][4]);
  append(mvec, mValues[idx][5]);

  gens.push_back(mValues[idx][7]);
  gens.push_back(mValues[idx][8]);

  ords.push_back(mValues[idx][10]);

  cout << "*** Test_Chagri: c=" << c
       << ", N=" << N
       << ", m=" << m
       << " (=" << mvec << "), gens="<<gens<<", ords="<<ords << endl
       << ", " << n_slots << " elements in the state"
       << ", " << slot_size << " is the field size of the elements"
       << ", state is " << n_slots*slot_size <<" bits."
       << endl;

  setTimersOn();
  double tm = -GetTime();
  Context context(m, p, /*r=*/1, gens, ords); 
#if (NTL_SP_NBITS>=50) // 64-bit machines
  //context.bitsPerLevel = B;
#endif
  context.zMStar.set_cM(mValues[idx][13]/100.0); // the ring constant
  buildModChain(context, N, c);

  {IndexSet allPrimes(0,context.numPrimes()-1);
   cout <<"  "<<context.numPrimes()<<" primes ("
       <<context.ctxtPrimes.card()<<" ctxt/"
       <<context.specialPrimes.card()<<" special), total bitsize="
	<<context.logOfProduct(allPrimes)
	<<", security level: "<<context.securityLevel() << endl;}

  long e = mValues[idx][3] / slot_size; 
  cout << "  "<<context.zMStar.getNSlots()<<" slots ("
       << (context.zMStar.getNSlots()/n_slots)<<" blocks) per ctxt";
  if (boot && packed)
    cout << ". x"<<e<<" ctxts";
  cout << endl;

  cout << "ZMSTAR P ORDER: " << context.zMStar.getOrdP() << endl;

  tm = -GetTime();
  SecKey secretKey(context);
  PubKey& publicKey = secretKey;
  secretKey.GenSecKey(64);     


  long ord = context.zMStar.OrderOf(0);
  cout << "Generator: " << context.zMStar.ZmStarGen(0) << endl;
  cout << "Order: " << ord << endl;

  for (long i = 1; i < n_slots; i++) { // rotation along 1st dim by size i*ord/3
    long exp = i*ord/n_slots;
    long val = PowerMod(context.zMStar.ZmStarGen(0), exp, m); // val = g^exp

    // From s(X^val) to s(X)
    secretKey.GenKeySWmatrix(1, val);
    if (!context.zMStar.SameOrd(0))
      // also from s(X^{1/val}) to s(X)
      secretKey.GenKeySWmatrix(1, InvMod(val,m));
  }


   addFrbMatrices(secretKey);      // Also add Frobenius key-switching

  tm += GetTime();

  tm = -GetTime();

  Chaghri hChaghri(context, n_slots, slot_size); // compute Chaghri-specific key-independent tables
  EncryptedArrayDerived<PA_GF2>& ea2 = hChaghri.getEA();

  long blocksPerCtxt = ea2.size() / n_slots;  

  long nBlocks;
  nBlocks = blocksPerCtxt;

  nBlocks =1; //For testing purposes

  Vec<GF2X> ptxt(INIT_SIZE, nBlocks*n_slots);
  Vec<GF2X> key(INIT_SIZE, n_slots); 

  // Choose random key, data
  GF2X rnd;
  for(int i=0; i<nBlocks*n_slots; i++){
    random(rnd, slot_size);
    ptxt[i] = rnd;
  }
  for(int i=0; i<nBlocks*n_slots; i++){
    random(rnd, slot_size);
    key[i] = rnd;
  }
 
  //Encrypt the Chaghri key
  vector< Ctxt > encryptedChaghrikey;
  hChaghri.encryptChaghrikey(encryptedChaghrikey, key, publicKey,n_slots,slot_size);

  tm += GetTime();

 
  // Perform homomorphic Chaghri
  cout << "Chaghri decryption "<< std::flush;
  vector< Ctxt > doublyEncrypted;

  tm = -GetTime();
  hChaghri.chaghri_dec(doublyEncrypted, encryptedChaghrikey, ptxt, publicKey, n_slots, slot_size);
  tm += GetTime();
  cout << "Chaghri done in "<<tm<<" seconds****************\n";
  Vec<ZZX> poly(INIT_SIZE, doublyEncrypted.size());
  Vec<GF2X> chaghri_res(INIT_SIZE, nBlocks*n_slots);
  for (long i=0; i<poly.length(); i++)
    secretKey.Decrypt(poly[i], doublyEncrypted[i]);

  decode4chaghri(chaghri_res, poly, ea2,n_slots);

  resetAllTimers();


#if (defined(__unix__) || defined(__unix) || defined(unix))
  struct rusage rusage;
  getrusage( RUSAGE_SELF, &rusage );
  cout << "rusage.ru_maxrss="<<rusage.ru_maxrss << endl << endl;
#endif
}

