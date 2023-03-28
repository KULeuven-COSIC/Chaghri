/** chaghri.cpp - homomorphic Chaghri using HElib
 */
namespace std {} using namespace std;
namespace NTL {} using namespace NTL;
namespace helib {} using namespace helib;
#include <cstring>
#include "chaghri.h"


static long findBaseLevel(const Ctxt& c);


static const uint8_t aesPolyBytes_63[] = { 0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x80}; // X^63 + X + 1
const GF2X Chaghri::aesPoly_63 = GF2XFromBytes(aesPolyBytes_63, 8);

Chaghri::Chaghri(const Context& context, long n_slots, long slot_size): ea2(context,aesPoly_63,context.alMod)
{
  ea2 = EncryptedArrayDerived<PA_GF2>(context,aesPoly_63,context.alMod);
}

void Chaghri::encryptChaghrikey(vector<Ctxt>& eKey, Vec<GF2X> chaghriKey,
			   const PubKey& hePK, long n_slots, long slot_size) const
{
  extern void chaghri_schedule(Vec<GF2X> key,GF2X final_keys[]); 
  // Compute the key expansion
  GF2X KeySchedule[54];
  chaghri_schedule(chaghriKey, KeySchedule);

  long blocksPerCtxt = ea2.size() / 3;

  Vec<GF2X> expand_key(INIT_SIZE, 18*blocksPerCtxt*3);

GF2X roundKey1, roundKey2, roundKey3;
  for (long i=0; i<18; i++) {
    roundKey1 = KeySchedule[3*i];
    roundKey2 = KeySchedule[3*i + 1];
    roundKey3 = KeySchedule[3*i + 2];
    for (long j=0; j<blocksPerCtxt; j++){
      expand_key[3*(i*blocksPerCtxt +j)] = roundKey1;
      expand_key[3*(i*blocksPerCtxt +j)+1] = roundKey2;
      expand_key[3*(i*blocksPerCtxt +j)+2] = roundKey3;}
  }
  Vec<ZZX> encodedKeys;
  encode4Chaghrigf2(encodedKeys, expand_key, ea2, n_slots); // encode as HE plaintext

  {Ctxt tmpCtxt(hePK);
  eKey.resize(encodedKeys.length(), tmpCtxt);}

  for (long i=0; i<(long)eKey.size(); i++)   // encode ptxt as HE ctxt
  hePK.Encrypt(eKey[i], encodedKeys[i]);
}


void Chaghri::chaghri_dec(vector<Ctxt>& eData, const vector<Ctxt>& eKey,  const PubKey& hePK, long n_slots, long slot_size) const
{
  long rotAmount = ea2.getContext().zMStar.OrderOf(0) / n_slots;

   /////////////////////ENCODING CONSTANTS/////////////////////////////////////////////////

  vector<GF2X> scratch; 

  /////////////////////c1
  scratch.resize(ea2.size());
  ZZX c1;
  GF2X c1_;
  SetCoeff(c1_,60,1); SetCoeff(c1_,59,1); SetCoeff(c1_,58,1); SetCoeff(c1_,56,1); SetCoeff(c1_,53,1);
  SetCoeff(c1_,52,1); SetCoeff(c1_,50,1); SetCoeff(c1_,48,1); SetCoeff(c1_,46,1); SetCoeff(c1_,44,1);
  SetCoeff(c1_,43,1); SetCoeff(c1_,40,1); SetCoeff(c1_,39,1); SetCoeff(c1_,38,1); SetCoeff(c1_,37,1);
  SetCoeff(c1_,35,1); SetCoeff(c1_,33,1); SetCoeff(c1_,31,1); SetCoeff(c1_,28,1); SetCoeff(c1_,27,1);
  SetCoeff(c1_,26,1); SetCoeff(c1_,23,1); SetCoeff(c1_,21,1); SetCoeff(c1_,20,1); SetCoeff(c1_,18,1);
  SetCoeff(c1_,16,1); SetCoeff(c1_,15,1); SetCoeff(c1_,14,1); SetCoeff(c1_,12,1); SetCoeff(c1_,10,1);
  SetCoeff(c1_,9,1); SetCoeff(c1_,6,1); SetCoeff(c1_,5,1); SetCoeff(c1_,2,1); SetCoeff(c1_,1,1);
  for (long i = 0; i < ea2.size(); i++)
    scratch[i] = c1_;
  ea2.encode(c1, scratch);       // encode these slots


  /////////////////////c2
  scratch.resize(ea2.size());
  ZZX c2;
  GF2X c2_;
  SetCoeff(c2_,62,1); SetCoeff(c2_,61,1); SetCoeff(c2_,60,1); SetCoeff(c2_,57,1); SetCoeff(c2_,56,1);
  SetCoeff(c2_,51,1); SetCoeff(c2_,50,1); SetCoeff(c2_,49,1); SetCoeff(c2_,48,1); SetCoeff(c2_,46,1);
  SetCoeff(c2_,45,1); SetCoeff(c2_,44,1); SetCoeff(c2_,43,1); SetCoeff(c2_,40,1); SetCoeff(c2_,37,1);
  SetCoeff(c2_,33,1); SetCoeff(c2_,32,1); SetCoeff(c2_,31,1); SetCoeff(c2_,30,1); SetCoeff(c2_,29,1);
  SetCoeff(c2_,25,1); SetCoeff(c2_,22,1); SetCoeff(c2_,20,1); SetCoeff(c2_,18,1); SetCoeff(c2_,17,1);
  SetCoeff(c2_,15,1); SetCoeff(c2_,14,1); SetCoeff(c2_,12,1); SetCoeff(c2_,11,1); SetCoeff(c2_,10,1);
  SetCoeff(c2_,5,1); SetCoeff(c2_,1,1); SetCoeff(c2_,0,1); 
  for (long i = 0; i < ea2.size(); i++)  // set all slots to row
    scratch[i] = c2_;
  
  ea2.encode(c2, scratch);       // encode these slots

  /////////////////////c3
  scratch.resize(ea2.size());
  ZZX c3;
  GF2X c3_;
  SetCoeff(c3_,61,1); SetCoeff(c3_,59,1); SetCoeff(c3_,57,1); SetCoeff(c3_,54,1); SetCoeff(c3_,53,1);
  SetCoeff(c3_,52,1); SetCoeff(c3_,50,1); SetCoeff(c3_,49,1); SetCoeff(c3_,48,1); SetCoeff(c3_,47,1);
  SetCoeff(c3_,45,1); SetCoeff(c3_,42,1); SetCoeff(c3_,40,1); SetCoeff(c3_,37,1); SetCoeff(c3_,36,1);
  SetCoeff(c3_,35,1); SetCoeff(c3_,34,1); SetCoeff(c3_,33,1); SetCoeff(c3_,31,1); SetCoeff(c3_,29,1);
  SetCoeff(c3_,26,1); SetCoeff(c3_,24,1); SetCoeff(c3_,23,1); SetCoeff(c3_,21,1); SetCoeff(c3_,20,1);
  SetCoeff(c3_,19,1); SetCoeff(c3_,17,1); SetCoeff(c3_,14,1); SetCoeff(c3_,13,1); SetCoeff(c3_,8,1);
  SetCoeff(c3_,6,1); SetCoeff(c3_,4,1); SetCoeff(c3_,0,1); 
  for (long i = 0; i < ea2.size(); i++)  // set all slots to row
    scratch[i] = c3_;
  
  ea2.encode(c3, scratch);       // encode these slots

  /////////////////////c4
  scratch.resize(ea2.size());
  ZZX c4;
  GF2X c4_;
  SetCoeff(c4_,59,1); SetCoeff(c4_,55,1); SetCoeff(c4_,54,1); SetCoeff(c4_,53,1); SetCoeff(c4_,52,1);
  SetCoeff(c4_,50,1); SetCoeff(c4_,49,1); SetCoeff(c4_,46,1); SetCoeff(c4_,45,1); SetCoeff(c4_,42,1);
  SetCoeff(c4_,40,1); SetCoeff(c4_,38,1); SetCoeff(c4_,31,1); SetCoeff(c4_,30,1); SetCoeff(c4_,26,1);
  SetCoeff(c4_,24,1); SetCoeff(c4_,23,1); SetCoeff(c4_,22,1); SetCoeff(c4_,19,1); SetCoeff(c4_,15,1);
  SetCoeff(c1_,13,1); SetCoeff(c1_,12,1); SetCoeff(c1_,7,1); SetCoeff(c1_,2,1); SetCoeff(c1_,1,1);
  for (long i = 0; i < ea2.size(); i++)  // set all slots to row
    scratch[i] = c4_;
 
  ea2.encode(c4, scratch);       // encode these slots


  ///////////////////MDS
  scratch.resize(ea2.size());
  ZZX mds1;

  GF2X mds1_1;
  SetCoeff(mds1_1,6,1); 

  GF2X mds1_2;
  SetCoeff(mds1_2,9,1);  SetCoeff(mds1_2,8,1);  SetCoeff(mds1_2,7,1);

  GF2X mds1_3;
  SetCoeff(mds1_3,12,1);  SetCoeff(mds1_3,11,1);  SetCoeff(mds1_3,9,1);  SetCoeff(mds1_3,8,1); 

  for (long i = 0; i < ea2.size(); i++){  // set all slots to row
    if(i%3 == 0)
     scratch[i] = mds1_1;
    if(i%3 == 1)
     scratch[i] = mds1_2;
    if(i%3 == 2)
     scratch[i] = mds1_3;
  }
  ea2.encode(mds1, scratch);       // encode these slots

  scratch.resize(ea2.size());
  ZZX mds2;

  GF2X mds2_1;
  SetCoeff(mds2_1,5,1);  SetCoeff(mds2_1,4,1);  SetCoeff(mds2_1,3,1); 

  GF2X mds2_2;
  SetCoeff(mds2_2,8,1);  SetCoeff(mds2_2,4,1);

  GF2X mds2_3;
  SetCoeff(mds2_3,11,1);  SetCoeff(mds2_3,9,1);  SetCoeff(mds2_3,8,1);  SetCoeff(mds2_3,7,1); 
  SetCoeff(mds2_3,5,1);

  for (long i = 0; i < ea2.size(); i++){  // set all slots to row
    if(i%3 == 0)
     scratch[i] = mds2_1;
    if(i%3 == 1)
     scratch[i] = mds2_2;
    if(i%3 == 2)
     scratch[i] = mds2_3;
  }
  ea2.encode(mds2, scratch);       // encode these slots


  scratch.resize(ea2.size());
  ZZX mds3;

  GF2X mds3_1;
  SetCoeff(mds3_1,3,1);  SetCoeff(mds3_1,2,1);  SetCoeff(mds3_1,1,1);

  GF2X mds3_2;
  SetCoeff(mds3_2,6,1);  SetCoeff(mds3_2,5,1);  SetCoeff(mds3_2,3,1);  SetCoeff(mds3_2,2,1);

  GF2X mds3_3;
  SetCoeff(mds3_3,9,1);  SetCoeff(mds3_3,8,1);  SetCoeff(mds3_3,4,1);  SetCoeff(mds3_3,3,1);

  for (long i = 0; i < ea2.size(); i++){  // set all slots to row
    if(i%3 == 0)
     scratch[i] = mds3_1;
    if(i%3 == 1)
     scratch[i] = mds3_2;
    if(i%3 == 2)
     scratch[i] = mds3_3;
  }
  ea2.encode(mds3, scratch);       // encode these slots

  double tm;
  setTimersOn();
  tm = -GetTime();

  //KEY ADDITION
  for (long j=0; j<(long)eData.size(); j++) { 
    eData[0] += eKey[0]; 
  }

  for(int i=0; i<8; i++){
    
    cout << " level begin" << eData[0].naturalSize() << endl;

 //NON-LINEAR PERMUTATION X^{(2^k)+1} gcd(k, 63) = 1 gcd((2^k)+1, 2^63-1)=1  k=32   
    for (long j=0; j<(long)eData.size(); j++) { // GF2 affine transformation
      Ctxt tmp(eData[j]);
      eData[j].frobeniusAutomorph(32); 
      eData[j].multiplyBy(tmp);
    }

    for (long j=0; j<(long)eData.size(); j++) { // GF2 affine transformation
      Ctxt tmp(eData[j]);
      Ctxt tmp2(eData[j]);
      tmp.frobeniusAutomorph(8);  //c1*x^{2^8} 
      tmp.multByConstant(c1);
      tmp2.frobeniusAutomorph(2);  //c2*x^{2^2}
      tmp2.multByConstant(c2);
      eData[j].multByConstant(c3);
      eData[j] += tmp;
      eData[j] += tmp2;
      eData[j].addConstant(c4);
    }


    //MATRIX MULTIPLICATION
    for (long j=0; j<(long)eData.size(); j++) { 
      vector<Ctxt> rows_multiplied;
      Ctxt orig(eData[j]);
      eData[j].multByConstant(mds1);
      rows_multiplied.push_back(eData[j]);


      Ctxt tmp(orig);
      ea2.rotate1D(tmp, 0, (1)*rotAmount);
      tmp.multByConstant(mds2);
      rows_multiplied.push_back(tmp);

      tmp = orig;
      ea2.rotate1D(tmp, 0, (2)*rotAmount);
      tmp.multByConstant(mds2);
      rows_multiplied.push_back(tmp);

      for(long k=1; k<n_slots; k++){
        eData[j] += rows_multiplied[k];
      }   
    }

    //KEY ADDITION
    for (long j=0; j<(long)eData.size(); j++) { 
      eData[0] += eKey[2*i+1]; 
    }
    
    //NON-LINEAR PERMUTATION X^{(2^k)+1} gcd(k, 63) = 1 gcd((2^k)+1, 2^63-1)=1  k=32   
    for (long j=0; j<(long)eData.size(); j++) { // GF2 affine transformation
      Ctxt tmp(eData[j]);
      eData[j].frobeniusAutomorph(32); 
      eData[j].multiplyBy(tmp);
    }


for (long j=0; j<(long)eData.size(); j++) { // GF2 affine transformation
      Ctxt tmp(eData[j]);
      Ctxt tmp2(eData[j]);
      tmp.frobeniusAutomorph(8);  //c1*x^{2^8} 
      tmp.multByConstant(c1);
      tmp2.frobeniusAutomorph(2);  //c2*x^{2^2}
      tmp2.multByConstant(c2);
      eData[j].multByConstant(c3);
      eData[j] += tmp;
      eData[j] += tmp2;
      eData[j].addConstant(c4);
}


    //MATRIX MULTIPLICATION
    for (long j=0; j<(long)eData.size(); j++) { 
      vector<Ctxt> rows_multiplied;
      Ctxt orig(eData[j]);
      eData[j].multByConstant(mds1);
      rows_multiplied.push_back(eData[j]);


      Ctxt tmp(orig);
      ea2.rotate1D(tmp, 0, (1)*rotAmount);
      tmp.multByConstant(mds2);
      rows_multiplied.push_back(tmp);

      tmp = orig;
      ea2.rotate1D(tmp, 0, (2)*rotAmount);
      tmp.multByConstant(mds2);
      rows_multiplied.push_back(tmp);

      for(long k=1; k<n_slots; k++){
        eData[j] += rows_multiplied[k];
      }   
    }

    //KEY ADDITION
    for (long j=0; j<(long)eData.size(); j++) { 
      eData[0] += eKey[2*i+2]; 
    }
    cout << " level: " << eData[0].naturalSize() << endl;
  }
  cout << "final level: " << eData[0].naturalSize() << endl;
	tm += GetTime();
	cout << " done in "<<tm<<" seconds****************\n";
}


void Chaghri::chaghri_dec(vector<Ctxt>& eData, const vector<Ctxt>& chaghriKey,
		       const Vec<GF2X> inBytes, const PubKey& hePK, long n_slots, long slot_size) const
{
  {Vec<ZZX> encodedBytes;
  encode4Chaghrigf2(encodedBytes, inBytes, ea2, n_slots); // encode as HE plaintext

  eData.resize(encodedBytes.length(), Ctxt(ZeroCtxtLike,chaghriKey[0]));
  for (long i=0; i<(long)eData.size(); i++)   // encode ptxt as HE ctxt
//hePK.Encrypt(eData[i], encodedBytes[i]);
eData[i].DummyEncrypt(encodedBytes[i]);
}

 chaghri_dec(eData, chaghriKey,hePK, n_slots, slot_size); // do the real work

}





void encode4Chaghrigf2(Vec<ZZX>& encData, const Vec<GF2X>& data,
		const EncryptedArrayDerived<PA_GF2>& ea2, long n_slots)
{
  long nBlocks = divc(data.length(), n_slots); 
  long blocksPerCtxt = ea2.size() / n_slots;  
  long nCtxt = divc(nBlocks, blocksPerCtxt);


  encData.SetLength(nCtxt);
  for (long i=0; i<nCtxt; i++) {
    vector<GF2X> slots(ea2.size(), GF2X::zero());
    for (long j=0; j<blocksPerCtxt; j++) { // j is the block number in this ctxt
      long blockShift = (i*blocksPerCtxt +j)*n_slots;  // point to block
      for (long k=0; k<n_slots; k++) {         // k is the byte number in this block
	long byteIdx= blockShift+ k;      // column orded within block
	if (byteIdx < data.length()) {
	  long slotIdx = j + k*blocksPerCtxt;
	  slots[slotIdx]=data[byteIdx];
	}
      }


    }

    ea2.encode(encData[i], slots);
  }
}


void decode4chaghri(Vec<GF2X>& data, const Vec<ZZX>& encData,
		const EncryptedArrayDerived<PA_GF2>& ea2, long n_slots)
{
  long nBytes = encData.length() * ea2.size(); 
  if (data.length()<=0 || data.length()>nBytes)
    data.SetLength(nBytes);
  long nBlocks = divc(data.length(),n_slots);      
  long blocksPerCtxt = ea2.size() / n_slots;       
  long nCtxt = divc(nBlocks, blocksPerCtxt);     

  cout <<"Decryption result:"<< endl;
  vector<GF2X> slots;
  for (long i=0; i<nCtxt; i++) {         
    ea2.decode(slots, encData[i]);
    for (long j=0; j<blocksPerCtxt; j++) { 
      long blockShift = (i*blocksPerCtxt +j)*n_slots;  
      for (long k=0; k<n_slots; k++) {       
	long byteIdx= blockShift +k;      
	if (byteIdx < data.length()) {
	  long slotIdx = j + k*blocksPerCtxt;
          cout << endl;
          cout << slots[slotIdx] << endl;
	}
      }
    }
  }
}

static long findBaseLevel(const Ctxt& c)
{
  return long(c.naturalSize() / 23); 
}
