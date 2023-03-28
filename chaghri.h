/** chaghri.h - homomorphic Chaghri using HElib
 */
#include <stdint.h>
#include <NTL/ZZX.h>
#include <NTL/GF2X.h>
#include "helib/EncryptedArray.h"
#include "helib/hypercube.h"

#ifdef USE_ZZX_POLY
#define PolyType ZZX
#else
#if (ALT_CRT)
#define PolyType AltCRT
#else
#define PolyType DoubleCRT
#endif
#endif

class Chaghri {
 
  EncryptedArrayDerived<PA_GF2> ea2;

public:
 
  static const GF2X aesPoly_63;

  explicit Chaghri(const Context& context, long n_slots, long slot_size);

  void encryptChaghrikey(vector<Ctxt>& eKey, Vec<GF2X> chaghriKey,
		     const PubKey& hePK, long n_slots, long slot_size) const;

  void chaghri_dec(vector<Ctxt>& eData, const vector<Ctxt>& eKey,
		 const Vec<GF2X> inBytes, const PubKey& hePK, long n_slots, long slot_size) const;

  void chaghri_dec(vector<Ctxt>& eData, const vector<Ctxt>& eKey, const PubKey& hePK, long n_slots, long slot_size) const;


EncryptedArrayDerived<PA_GF2>& getEA()  { return ea2; }
};

// Encode/decode Chaghri plaintext/ciphertext bytes as native HE plaintext
void encode4Chaghrigf2(Vec<ZZX>& encData, const Vec<GF2X>& data,
		const EncryptedArrayDerived<PA_GF2>& ea2, long n_slots);
void decode4chaghri(Vec<GF2X>& data, const Vec<ZZX>& encData,
		const EncryptedArrayDerived<PA_GF2>& ea2, long n_slots);
