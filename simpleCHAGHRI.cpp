namespace std {} using namespace std;
namespace NTL {} using namespace NTL;
namespace helib {} using namespace helib;
#include<cstdlib>
#include<cstdio>
#include<helib/helib.h>

#define elt 3

void chaghri_schedule(Vec<GF2X> key, GF2X final_keys[]){

GF2X irreducible_poly;
SetCoeff(irreducible_poly,63,1); SetCoeff(irreducible_poly,1,1); SetCoeff(irreducible_poly,0,1);
GF2E::init(irreducible_poly);

/*GF2X t;
SetCoeff(t,0,1);
Vec<GF2X> final_keys(INIT_SIZE, 54);*/

// Round constants
// Round 1
GF2X r1_1;
SetCoeff(r1_1,61,1);  SetCoeff(r1_1,60,1);  SetCoeff(r1_1,57,1);  SetCoeff(r1_1,56,1);  SetCoeff(r1_1,55,1);  SetCoeff(r1_1,54,1);  SetCoeff(r1_1,51,1);  SetCoeff(r1_1,49,1);  
SetCoeff(r1_1,47,1);  SetCoeff(r1_1,45,1);  SetCoeff(r1_1,44,1);  SetCoeff(r1_1,43,1);  SetCoeff(r1_1,41,1);  SetCoeff(r1_1,39,1);  SetCoeff(r1_1,36,1);  SetCoeff(r1_1,35,1);  
SetCoeff(r1_1,34,1);  SetCoeff(r1_1,33,1);  SetCoeff(r1_1,29,1);  SetCoeff(r1_1,27,1);  SetCoeff(r1_1,26,1);  SetCoeff(r1_1,25,1);  SetCoeff(r1_1,23,1);  SetCoeff(r1_1,21,1);  
SetCoeff(r1_1,16,1);  SetCoeff(r1_1,14,1);  SetCoeff(r1_1,12,1);  SetCoeff(r1_1,8,1);  
SetCoeff(r1_1,3,1);  SetCoeff(r1_1,2,1);  SetCoeff(r1_1,1,1);  SetCoeff(r1_1,0,1);
GF2E r1_1_ = conv<GF2E>(r1_1);


GF2X r1_2;
SetCoeff(r1_2,62,1);  SetCoeff(r1_2,59,1);  SetCoeff(r1_2,54,1);  SetCoeff(r1_2,53,1);  SetCoeff(r1_2,52,1);  SetCoeff(r1_2,51,1);  SetCoeff(r1_2,49,1);  SetCoeff(r1_2,47,1);  
SetCoeff(r1_2,45,1);  SetCoeff(r1_2,44,1);  SetCoeff(r1_2,42,1);  SetCoeff(r1_2,41,1);  SetCoeff(r1_2,38,1);  SetCoeff(r1_2,37,1);  SetCoeff(r1_2,35,1);  SetCoeff(r1_2,34,1);  
SetCoeff(r1_2,32,1);  SetCoeff(r1_2,31,1);  SetCoeff(r1_2,30,1);  SetCoeff(r1_2,29,1);  SetCoeff(r1_2,28,1);  SetCoeff(r1_2,22,1);  SetCoeff(r1_2,21,1);  SetCoeff(r1_2,19,1);  
SetCoeff(r1_2,14,1);  SetCoeff(r1_2,12,1);  SetCoeff(r1_2,10,1);  SetCoeff(r1_2,8,1);  
SetCoeff(r1_2,7,1);  SetCoeff(r1_2,6,1);  SetCoeff(r1_2,3,1);  SetCoeff(r1_2,0,1); 
GF2E r1_2_ = conv<GF2E>(r1_2);


GF2X r1_3;
SetCoeff(r1_3,61,1);  SetCoeff(r1_3,60,1);  SetCoeff(r1_3,57,1);  SetCoeff(r1_3,56,1);  SetCoeff(r1_3,52,1);  SetCoeff(r1_3,51,1);  SetCoeff(r1_3,46,1);  SetCoeff(r1_3,44,1);  
SetCoeff(r1_3,43,1);  SetCoeff(r1_3,42,1);  SetCoeff(r1_3,41,1);  SetCoeff(r1_3,37,1);  SetCoeff(r1_3,35,1);  SetCoeff(r1_3,31,1);  SetCoeff(r1_3,28,1);  SetCoeff(r1_3,26,1);  
SetCoeff(r1_3,22,1);  SetCoeff(r1_3,21,1);  SetCoeff(r1_3,19,1);  SetCoeff(r1_3,15,1);  SetCoeff(r1_3,2,1);  SetCoeff(r1_3,1,1);   SetCoeff(r1_3,0,1); 
GF2E r1_3_ = conv<GF2E>(r1_3);


GF2X r1_4;
SetCoeff(r1_4,56,1);  SetCoeff(r1_4,54,1);  SetCoeff(r1_4,52,1);  SetCoeff(r1_4,51,1);  SetCoeff(r1_4,48,1);  SetCoeff(r1_4,45,1);  SetCoeff(r1_4,41,1);  SetCoeff(r1_4,39,1);  
SetCoeff(r1_4,36,1);  SetCoeff(r1_4,33,1);  SetCoeff(r1_4,28,1);  SetCoeff(r1_4,27,1);  SetCoeff(r1_4,25,1);  SetCoeff(r1_4,23,1);  SetCoeff(r1_4,19,1);  SetCoeff(r1_4,15,1);  
SetCoeff(r1_4,13,1);  SetCoeff(r1_4,12,1);  SetCoeff(r1_4,11,1);  SetCoeff(r1_4,9,1);  
SetCoeff(r1_4,8,1);  SetCoeff(r1_4,6,1);  SetCoeff(r1_4,4,1);  SetCoeff(r1_4,2,1);  
SetCoeff(r1_4,1,1); 
GF2E r1_4_ = conv<GF2E>(r1_4);


GF2X r1_5;
SetCoeff(r1_5,62,1);  SetCoeff(r1_5,61,1);  SetCoeff(r1_5,58,1);  SetCoeff(r1_5,54,1);  SetCoeff(r1_5,51,1);  SetCoeff(r1_5,50,1);  SetCoeff(r1_5,49,1);  SetCoeff(r1_5,47,1);  
SetCoeff(r1_5,46,1);  SetCoeff(r1_5,42,1);  SetCoeff(r1_5,41,1);  SetCoeff(r1_5,40,1);  SetCoeff(r1_5,39,1);  SetCoeff(r1_5,34,1);  SetCoeff(r1_5,33,1);  SetCoeff(r1_5,32,1);  
SetCoeff(r1_5,27,1);  SetCoeff(r1_5,25,1);  SetCoeff(r1_5,24,1);  SetCoeff(r1_5,23,1);  SetCoeff(r1_5,21,1);  SetCoeff(r1_5,19,1);  SetCoeff(r1_5,17,1);  SetCoeff(r1_5,16,1);  
SetCoeff(r1_5,14,1);  SetCoeff(r1_5,8,1);  SetCoeff(r1_5,7,1);  SetCoeff(r1_5,5,1);  
SetCoeff(r1_5,1,1);  SetCoeff(r1_5,0,1);
GF2E r1_5_ = conv<GF2E>(r1_5);


GF2X r1_6;
SetCoeff(r1_6,62,1);  SetCoeff(r1_6,61,1);  SetCoeff(r1_6,58,1);  SetCoeff(r1_6,54,1);  SetCoeff(r1_6,53,1);  SetCoeff(r1_6,52,1);  SetCoeff(r1_6,49,1);  SetCoeff(r1_6,44,1);  
SetCoeff(r1_6,39,1);  SetCoeff(r1_6,37,1);  SetCoeff(r1_6,35,1);  SetCoeff(r1_6,33,1);  SetCoeff(r1_6,32,1);  SetCoeff(r1_6,29,1);  SetCoeff(r1_6,27,1);  SetCoeff(r1_6,21,1);  
SetCoeff(r1_6,20,1);  SetCoeff(r1_6,18,1);  SetCoeff(r1_6,17,1);  SetCoeff(r1_6,16,1);  SetCoeff(r1_6,13,1);  SetCoeff(r1_6,12,1);  SetCoeff(r1_6,10,1);  SetCoeff(r1_6,9,1);  
SetCoeff(r1_6,8,1);  SetCoeff(r1_6,7,1);  SetCoeff(r1_6,5,1);  SetCoeff(r1_6,3,1);  
SetCoeff(r1_6,1,1); SetCoeff(r1_6,0,1);
GF2E r1_6_ = conv<GF2E>(r1_6); 


// Round 2
GF2X r2_1;
SetCoeff(r2_1,61,1);  SetCoeff(r2_1,60,1);  SetCoeff(r2_1,59,1);  SetCoeff(r2_1,58,1);  SetCoeff(r2_1,57,1);  SetCoeff(r2_1,54,1);  SetCoeff(r2_1,53,1);  SetCoeff(r2_1,51,1);  
SetCoeff(r2_1,50,1);  SetCoeff(r2_1,49,1);  SetCoeff(r2_1,47,1);  SetCoeff(r2_1,45,1);  SetCoeff(r2_1,44,1);  SetCoeff(r2_1,40,1);  SetCoeff(r2_1,39,1);  SetCoeff(r2_1,38,1);  
SetCoeff(r2_1,36,1);  SetCoeff(r2_1,32,1);  SetCoeff(r2_1,30,1);  SetCoeff(r2_1,28,1);  SetCoeff(r2_1,27,1);  SetCoeff(r2_1,26,1);  SetCoeff(r2_1,25,1);  SetCoeff(r2_1,22,1);  
SetCoeff(r2_1,21,1);  SetCoeff(r2_1,20,1);  SetCoeff(r2_1,19,1);  SetCoeff(r2_1,17,1);  SetCoeff(r2_1,16,1);  SetCoeff(r2_1,14,1);  SetCoeff(r2_1,13,1);  SetCoeff(r2_1,9,1);  
SetCoeff(r2_1,7,1);  SetCoeff(r2_1,6,1);  SetCoeff(r2_1,5,1);  SetCoeff(r2_1,4,1);  
SetCoeff(r2_1,1,1);
GF2E r2_1_ = conv<GF2E>(r2_1);


GF2X r2_2;
SetCoeff(r2_2,62,1);  SetCoeff(r2_2,60,1);  SetCoeff(r2_2,59,1);  SetCoeff(r2_2,58,1);  SetCoeff(r2_2,57,1);  SetCoeff(r2_2,56,1);  SetCoeff(r2_2,55,1);  SetCoeff(r2_2,54,1);  
SetCoeff(r2_2,53,1);  SetCoeff(r2_2,50,1);  SetCoeff(r2_2,47,1);  SetCoeff(r2_2,45,1);  SetCoeff(r2_2,44,1);  SetCoeff(r2_2,41,1);  SetCoeff(r2_2,40,1);  SetCoeff(r2_2,39,1);  
SetCoeff(r2_2,38,1);  SetCoeff(r2_2,37,1);  SetCoeff(r2_2,35,1);  SetCoeff(r2_2,31,1);  SetCoeff(r2_2,28,1);  SetCoeff(r2_2,26,1);  SetCoeff(r2_2,25,1);  SetCoeff(r2_2,24,1);  
SetCoeff(r2_2,22,1);  SetCoeff(r2_2,19,1);  SetCoeff(r2_2,3,1);  SetCoeff(r2_2,0,1);
GF2E r2_2_ = conv<GF2E>(r2_2);


GF2X r2_3;
SetCoeff(r2_3,61,1);  SetCoeff(r2_3,59,1);  SetCoeff(r2_3,56,1);  SetCoeff(r2_3,53,1);  SetCoeff(r2_3,52,1);  SetCoeff(r2_3,49,1);  SetCoeff(r2_3,48,1);  SetCoeff(r2_3,47,1);  
SetCoeff(r2_3,44,1);  SetCoeff(r2_3,43,1);  SetCoeff(r2_3,42,1);  SetCoeff(r2_3,40,1);  SetCoeff(r2_3,39,1);  SetCoeff(r2_3,38,1);  SetCoeff(r2_3,36,1);  SetCoeff(r2_3,34,1);  
SetCoeff(r2_3,33,1);  SetCoeff(r2_3,32,1);  SetCoeff(r2_3,31,1);  SetCoeff(r2_3,30,1);  SetCoeff(r2_3,29,1);  SetCoeff(r2_3,26,1);  SetCoeff(r2_3,25,1);  SetCoeff(r2_3,24,1);  
SetCoeff(r2_3,23,1);  SetCoeff(r2_3,22,1);  SetCoeff(r2_3,21,1);  SetCoeff(r2_3,18,1);  SetCoeff(r2_3,16,1);  SetCoeff(r2_3,14,1);  SetCoeff(r2_3,12,1);  SetCoeff(r2_3,10,1);  
SetCoeff(r2_3,8,1);  SetCoeff(r2_3,6,1);  SetCoeff(r2_3,5,1);  SetCoeff(r2_3,0,1);
GF2E r2_3_ = conv<GF2E>(r2_3);


GF2X r2_4;
SetCoeff(r2_4,61,1);  SetCoeff(r2_4,59,1);  SetCoeff(r2_4,54,1);  SetCoeff(r2_4,51,1);  SetCoeff(r2_4,50,1);  SetCoeff(r2_4,48,1);  SetCoeff(r2_4,47,1);  SetCoeff(r2_4,46,1);  
SetCoeff(r2_4,45,1);  SetCoeff(r2_4,44,1);  SetCoeff(r2_4,42,1);  SetCoeff(r2_4,40,1);  SetCoeff(r2_4,39,1);  SetCoeff(r2_4,38,1);  SetCoeff(r2_4,37,1);  SetCoeff(r2_4,36,1);  
SetCoeff(r2_4,33,1);  SetCoeff(r2_4,31,1);  SetCoeff(r2_4,26,1);  SetCoeff(r2_4,24,1);  SetCoeff(r2_4,13,1);  SetCoeff(r2_4,11,1);  SetCoeff(r2_4,6,1);  SetCoeff(r2_4,1,1);   
SetCoeff(r2_4,0,1); 
GF2E r2_4_ = conv<GF2E>(r2_4);


GF2X r2_5;
SetCoeff(r2_5,62,1);  SetCoeff(r2_5,61,1);  SetCoeff(r2_5,60,1);  SetCoeff(r2_5,58,1);  SetCoeff(r2_5,52,1);  SetCoeff(r2_5,51,1);  SetCoeff(r2_5,49,1);  SetCoeff(r2_5,48,1);  
SetCoeff(r2_5,46,1);  SetCoeff(r2_5,45,1);  SetCoeff(r2_5,43,1);  SetCoeff(r2_5,41,1);  SetCoeff(r2_5,40,1);  SetCoeff(r2_5,39,1);  SetCoeff(r2_5,36,1);  SetCoeff(r2_5,32,1);  
SetCoeff(r2_5,28,1);  SetCoeff(r2_5,19,1);  SetCoeff(r2_5,17,1);  SetCoeff(r2_5,16,1);  SetCoeff(r2_5,15,1);  SetCoeff(r2_5,14,1);  SetCoeff(r2_5,10,1);  SetCoeff(r2_5,8,1);  
SetCoeff(r2_5,6,1);  SetCoeff(r2_5,2,1); SetCoeff(r2_5,1,1);
GF2E r2_5_ = conv<GF2E>(r2_5);


GF2X r2_6;
SetCoeff(r2_6,62,1);  SetCoeff(r2_6,61,1);  SetCoeff(r2_6,60,1);  SetCoeff(r2_6,57,1);  SetCoeff(r2_6,56,1);  SetCoeff(r2_6,54,1);  SetCoeff(r2_6,53,1);  SetCoeff(r2_6,52,1);  
SetCoeff(r2_6,47,1);  SetCoeff(r2_6,45,1);  SetCoeff(r2_6,38,1);  SetCoeff(r2_6,37,1);  SetCoeff(r2_6,35,1);  SetCoeff(r2_6,34,1);  SetCoeff(r2_6,33,1);  SetCoeff(r2_6,30,1);  
SetCoeff(r2_6,29,1);  SetCoeff(r2_6,23,1);  SetCoeff(r2_6,19,1);  SetCoeff(r2_6,12,1);  SetCoeff(r2_6,11,1);  SetCoeff(r2_6,8,1);  SetCoeff(r2_6,6,1);  SetCoeff(r2_6,4,1);  
SetCoeff(r2_6,2,1);  SetCoeff(r2_6,0,1);
GF2E r2_6_ = conv<GF2E>(r2_6);


//Round 3

GF2X r3_1;
SetCoeff(r3_1,62,1);  SetCoeff(r3_1,61,1);  SetCoeff(r3_1,60,1);  SetCoeff(r3_1,53,1);  SetCoeff(r3_1,52,1);  SetCoeff(r3_1,51,1);  SetCoeff(r3_1,48,1);  SetCoeff(r3_1,46,1);  
SetCoeff(r3_1,43,1);  SetCoeff(r3_1,42,1);  SetCoeff(r3_1,39,1);  SetCoeff(r3_1,38,1);  SetCoeff(r3_1,36,1);  SetCoeff(r3_1,29,1);  SetCoeff(r3_1,27,1);  SetCoeff(r3_1,23,1);  
SetCoeff(r3_1,22,1);  SetCoeff(r3_1,19,1);  SetCoeff(r3_1,17,1);  SetCoeff(r3_1,16,1);  SetCoeff(r3_1,15,1);  SetCoeff(r3_1,14,1);  SetCoeff(r3_1,11,1);  SetCoeff(r3_1,8,1);  
SetCoeff(r3_1,6,1);  SetCoeff(r3_1,1,1);  SetCoeff(r3_1,0,1);
GF2E r3_1_ = conv<GF2E>(r3_1);


GF2X r3_2;
SetCoeff(r3_2,60,1);  SetCoeff(r3_2,58,1);  SetCoeff(r3_2,57,1);  SetCoeff(r3_2,54,1);  SetCoeff(r3_2,52,1);  SetCoeff(r3_2,50,1);  SetCoeff(r3_2,46,1);  SetCoeff(r3_2,45,1);  
SetCoeff(r3_2,42,1);  SetCoeff(r3_2,40,1);  SetCoeff(r3_2,38,1);  SetCoeff(r3_2,37,1);  SetCoeff(r3_2,36,1);  SetCoeff(r3_2,35,1);  SetCoeff(r3_2,34,1);  SetCoeff(r3_2,33,1);  
SetCoeff(r3_2,29,1);  SetCoeff(r3_2,27,1);  SetCoeff(r3_2,25,1);  SetCoeff(r3_2,23,1);  SetCoeff(r3_2,22,1);  SetCoeff(r3_2,20,1);  SetCoeff(r3_2,17,1);  SetCoeff(r3_2,16,1);  
SetCoeff(r3_2,15,1);  SetCoeff(r3_2,14,1);  SetCoeff(r3_2,10,1);  SetCoeff(r3_2,5,1);  
SetCoeff(r3_2,3,1);  SetCoeff(r3_2,0,1); 
GF2E r3_2_ = conv<GF2E>(r3_2);


GF2X r3_3;
SetCoeff(r3_3,62,1);  SetCoeff(r3_3,61,1);  SetCoeff(r3_3,58,1);  SetCoeff(r3_3,57,1);  SetCoeff(r3_3,56,1);  SetCoeff(r3_3,55,1);  SetCoeff(r3_3,48,1);  SetCoeff(r3_3,47,1);  
SetCoeff(r3_3,45,1);  SetCoeff(r3_3,43,1);  SetCoeff(r3_3,41,1);  SetCoeff(r3_3,39,1);  SetCoeff(r3_3,37,1);  SetCoeff(r3_3,34,1);  SetCoeff(r3_3,30,1);  SetCoeff(r3_3,29,1);  
SetCoeff(r3_3,25,1);  SetCoeff(r3_3,24,1);  SetCoeff(r3_3,23,1);  SetCoeff(r3_3,21,1);  SetCoeff(r3_3,19,1);  SetCoeff(r3_3,16,1);  SetCoeff(r3_3,14,1);  SetCoeff(r3_3,13,1);  
SetCoeff(r3_3,10,1);  SetCoeff(r3_3,9,1);  SetCoeff(r3_3,8,1);  SetCoeff(r3_3,3,1); 
SetCoeff(r3_3,0,1);
GF2E r3_3_ = conv<GF2E>(r3_3);


GF2X r3_4;
SetCoeff(r3_4,62,1);  SetCoeff(r3_4,61,1);  SetCoeff(r3_4,60,1);  SetCoeff(r3_4,59,1);  SetCoeff(r3_4,58,1);  SetCoeff(r3_4,57,1);  SetCoeff(r3_4,53,1);  SetCoeff(r3_4,52,1);  
SetCoeff(r3_4,50,1);  SetCoeff(r3_4,49,1);  SetCoeff(r3_4,48,1);  SetCoeff(r3_4,45,1);  SetCoeff(r3_4,43,1);  SetCoeff(r3_4,42,1);  SetCoeff(r3_4,41,1);  SetCoeff(r3_4,37,1);  
SetCoeff(r3_4,36,1);  SetCoeff(r3_4,35,1);  SetCoeff(r3_4,34,1);  SetCoeff(r3_4,31,1);  SetCoeff(r3_4,30,1);  SetCoeff(r3_4,29,1);  SetCoeff(r3_4,28,1);  SetCoeff(r3_4,27,1);  
SetCoeff(r3_4,26,1);  SetCoeff(r3_4,24,1);  SetCoeff(r3_4,23,1);  SetCoeff(r3_4,21,1);  SetCoeff(r3_4,19,1);  SetCoeff(r3_4,18,1);  SetCoeff(r3_4,14,1);  SetCoeff(r3_4,10,1);  
SetCoeff(r3_4,4,1);
GF2E r3_4_ = conv<GF2E>(r3_4);


GF2X r3_5;
SetCoeff(r3_5,62,1);  SetCoeff(r3_5,57,1);  SetCoeff(r3_5,54,1);  SetCoeff(r3_5,52,1);  SetCoeff(r3_5,51,1);  SetCoeff(r3_5,50,1);  SetCoeff(r3_5,47,1);  SetCoeff(r3_5,44,1);  
SetCoeff(r3_5,43,1);  SetCoeff(r3_5,40,1);  SetCoeff(r3_5,37,1);  SetCoeff(r3_5,36,1);  SetCoeff(r3_5,35,1);  SetCoeff(r3_5,33,1);  SetCoeff(r3_5,25,1);  SetCoeff(r3_5,23,1);  
SetCoeff(r3_5,20,1);  SetCoeff(r3_5,19,1);  SetCoeff(r3_5,18,1);  SetCoeff(r3_5,12,1);  SetCoeff(r3_5,8,1);  SetCoeff(r3_5,6,1);  SetCoeff(r3_5,5,1);  SetCoeff(r3_5,2,1);
GF2E r3_5_ = conv<GF2E>(r3_5);


GF2X r3_6;
SetCoeff(r3_6,60,1);  SetCoeff(r3_6,58,1);  SetCoeff(r3_6,57,1);  SetCoeff(r3_6,56,1);  SetCoeff(r3_6,54,1);  SetCoeff(r3_6,49,1);  SetCoeff(r3_6,48,1);  SetCoeff(r3_6,47,1);  
SetCoeff(r3_6,45,1);  SetCoeff(r3_6,41,1);  SetCoeff(r3_6,39,1);  SetCoeff(r3_6,38,1);  SetCoeff(r3_6,37,1);  SetCoeff(r3_6,34,1);  SetCoeff(r3_6,31,1);  SetCoeff(r3_6,27,1);  
SetCoeff(r3_6,25,1);  SetCoeff(r3_6,24,1);  SetCoeff(r3_6,21,1);  SetCoeff(r3_6,20,1);  SetCoeff(r3_6,18,1);  SetCoeff(r3_6,13,1);  SetCoeff(r3_6,9,1);  SetCoeff(r3_6,8,1);  
SetCoeff(r3_6,6,1);  SetCoeff(r3_6,3,1);  SetCoeff(r3_6,1,1);  SetCoeff(r3_6,0,1);
GF2E r3_6_ = conv<GF2E>(r3_6);


//Round 4
GF2X r4_1;
SetCoeff(r4_1,62,1);  SetCoeff(r4_1,61,1);  SetCoeff(r4_1,59,1);  SetCoeff(r4_1,52,1);  SetCoeff(r4_1,48,1);  SetCoeff(r4_1,45,1);  SetCoeff(r4_1,43,1);  SetCoeff(r4_1,40,1);  
SetCoeff(r4_1,35,1);  SetCoeff(r4_1,34,1);  SetCoeff(r4_1,29,1);  SetCoeff(r4_1,26,1);  SetCoeff(r4_1,23,1);  SetCoeff(r4_1,20,1);  SetCoeff(r4_1,19,1);  SetCoeff(r4_1,18,1);  
SetCoeff(r4_1,17,1);  SetCoeff(r4_1,15,1);  SetCoeff(r4_1,14,1);  SetCoeff(r4_1,11,1);  SetCoeff(r4_1,9,1);  SetCoeff(r4_1,8,1);  SetCoeff(r4_1,5,1);  SetCoeff(r4_1,4,1);  
SetCoeff(r4_1,3,1);
GF2E r4_1_ = conv<GF2E>(r4_1);


GF2X r4_2;
SetCoeff(r4_2,62,1);  SetCoeff(r4_2,61,1);  SetCoeff(r4_2,60,1);  SetCoeff(r4_2,56,1);  SetCoeff(r4_2,55,1);  SetCoeff(r4_2,53,1);  SetCoeff(r4_2,52,1);  SetCoeff(r4_2,49,1);  
SetCoeff(r4_2,48,1);  SetCoeff(r4_2,47,1);  SetCoeff(r4_2,41,1);  SetCoeff(r4_2,38,1);  SetCoeff(r4_2,35,1);  SetCoeff(r4_2,34,1);  SetCoeff(r4_2,32,1);  SetCoeff(r4_2,31,1);  
SetCoeff(r4_2,24,1);  SetCoeff(r4_2,23,1);  SetCoeff(r4_2,20,1);  SetCoeff(r4_2,19,1);  SetCoeff(r4_2,17,1);  SetCoeff(r4_2,16,1);  SetCoeff(r4_2,15,1);  SetCoeff(r4_2,14,1);  
SetCoeff(r4_2,11,1);  SetCoeff(r4_2,8,1);  SetCoeff(r4_2,5,1);  SetCoeff(r4_2,3,1);  
SetCoeff(r4_2,2,1);
GF2E r4_2_ = conv<GF2E>(r4_2);


GF2X r4_3;
SetCoeff(r4_3,61,1);  SetCoeff(r4_3,60,1);  SetCoeff(r4_3,58,1);  SetCoeff(r4_3,57,1);  SetCoeff(r4_3,56,1);  SetCoeff(r4_3,55,1);  SetCoeff(r4_3,53,1);  SetCoeff(r4_3,50,1);  
SetCoeff(r4_3,49,1);  SetCoeff(r4_3,44,1);  SetCoeff(r4_3,39,1);  SetCoeff(r4_3,37,1);  SetCoeff(r4_3,36,1);  SetCoeff(r4_3,35,1);  SetCoeff(r4_3,34,1);  SetCoeff(r4_3,31,1);  
SetCoeff(r4_3,30,1);  SetCoeff(r4_3,25,1);  SetCoeff(r4_3,24,1);  SetCoeff(r4_3,23,1);  SetCoeff(r4_3,19,1);  SetCoeff(r4_3,18,1);  SetCoeff(r4_3,15,1);  SetCoeff(r4_3,14,1);  
SetCoeff(r4_3,13,1);  SetCoeff(r4_3,7,1);  SetCoeff(r4_3,5,1);  SetCoeff(r4_3,3,1);  
SetCoeff(r4_3,2,1); SetCoeff(r4_3,0,1);
GF2E r4_3_ = conv<GF2E>(r4_3);


GF2X r4_4;
SetCoeff(r4_4,60,1);  SetCoeff(r4_4,58,1);  SetCoeff(r4_4,57,1);  SetCoeff(r4_4,56,1);  SetCoeff(r4_4,52,1);  SetCoeff(r4_4,50,1);  SetCoeff(r4_4,49,1);  SetCoeff(r4_4,44,1);  
SetCoeff(r4_4,40,1);  SetCoeff(r4_4,39,1);  SetCoeff(r4_4,37,1);  SetCoeff(r4_4,35,1);  SetCoeff(r4_4,32,1);  SetCoeff(r4_4,31,1);  SetCoeff(r4_4,30,1);  SetCoeff(r4_4,26,1);  
SetCoeff(r4_4,23,1);  SetCoeff(r4_4,20,1);  SetCoeff(r4_4,19,1);  SetCoeff(r4_4,18,1);  SetCoeff(r4_4,17,1);  SetCoeff(r4_4,16,1);  SetCoeff(r4_4,15,1);  SetCoeff(r4_4,14,1);  
SetCoeff(r4_4,11,1);  SetCoeff(r4_4,10,1);  SetCoeff(r4_4,8,1);  SetCoeff(r4_4,4,1);  
SetCoeff(r4_4,1,1);
GF2E r4_4_ = conv<GF2E>(r4_4);


GF2X r4_5;
SetCoeff(r4_5,61,1);  SetCoeff(r4_5,60,1);  SetCoeff(r4_5,59,1);  SetCoeff(r4_5,58,1);  SetCoeff(r4_5,50,1);  SetCoeff(r4_5,43,1);  SetCoeff(r4_5,41,1);  SetCoeff(r4_5,38,1);  
SetCoeff(r4_5,37,1);  SetCoeff(r4_5,34,1);  SetCoeff(r4_5,32,1);  SetCoeff(r4_5,31,1);  SetCoeff(r4_5,28,1);  SetCoeff(r4_5,26,1);  SetCoeff(r4_5,25,1);  SetCoeff(r4_5,24,1);  
SetCoeff(r4_5,23,1);  SetCoeff(r4_5,22,1);  SetCoeff(r4_5,19,1);  SetCoeff(r4_5,17,1);  SetCoeff(r4_5,14,1);  SetCoeff(r4_5,12,1);  SetCoeff(r4_5,5,1);  SetCoeff(r4_5,1,1);
GF2E r4_5_ = conv<GF2E>(r4_5);


GF2X r4_6;
SetCoeff(r4_6,62,1);  SetCoeff(r4_6,61,1);  SetCoeff(r4_6,58,1);  SetCoeff(r4_6,57,1);  SetCoeff(r4_6,51,1);  SetCoeff(r4_6,50,1);  SetCoeff(r4_6,48,1);  SetCoeff(r4_6,46,1);  
SetCoeff(r4_6,44,1);  SetCoeff(r4_6,42,1);  SetCoeff(r4_6,41,1);  SetCoeff(r4_6,40,1);  SetCoeff(r4_6,35,1);  SetCoeff(r4_6,32,1);  SetCoeff(r4_6,26,1);  SetCoeff(r4_6,25,1);  
SetCoeff(r4_6,21,1);  SetCoeff(r4_6,18,1);  SetCoeff(r4_6,17,1);  SetCoeff(r4_6,16,1);  SetCoeff(r4_6,15,1);  SetCoeff(r4_6,14,1);  SetCoeff(r4_6,12,1);  SetCoeff(r4_6,10,1);  
SetCoeff(r4_6,8,1);  SetCoeff(r4_6,5,1);  SetCoeff(r4_6,2,1);
GF2E r4_6_ = conv<GF2E>(r4_6);


//Round 5
GF2X r5_1;
SetCoeff(r5_1,62,1);  SetCoeff(r5_1,58,1);  SetCoeff(r5_1,57,1);  SetCoeff(r5_1,54,1);  SetCoeff(r5_1,53,1);  SetCoeff(r5_1,52,1);  SetCoeff(r5_1,50,1);  SetCoeff(r5_1,49,1);  
SetCoeff(r5_1,48,1);  SetCoeff(r5_1,46,1);  SetCoeff(r5_1,40,1);  SetCoeff(r5_1,38,1);  SetCoeff(r5_1,37,1);  SetCoeff(r5_1,35,1);  SetCoeff(r5_1,34,1);  SetCoeff(r5_1,33,1);  
SetCoeff(r5_1,28,1);  SetCoeff(r5_1,27,1);  SetCoeff(r5_1,26,1);  SetCoeff(r5_1,25,1);  SetCoeff(r5_1,24,1);  SetCoeff(r5_1,23,1);  SetCoeff(r5_1,22,1);  SetCoeff(r5_1,21,1);  
SetCoeff(r5_1,18,1);  SetCoeff(r5_1,15,1);  SetCoeff(r5_1,14,1);  SetCoeff(r5_1,12,1);  SetCoeff(r5_1,11,1);  SetCoeff(r5_1,10,1);  SetCoeff(r5_1,9,1);  SetCoeff(r5_1,8,1);  
SetCoeff(r5_1,7,1);  SetCoeff(r5_1,6,1);  SetCoeff(r5_1,5,1);  SetCoeff(r5_1,1,1); 
SetCoeff(r5_1,0,1);
GF2E r5_1_ = conv<GF2E>(r5_1);


GF2X r5_2;
SetCoeff(r5_2,62,1);  SetCoeff(r5_2,61,1);  SetCoeff(r5_2,60,1);  SetCoeff(r5_2,59,1);  SetCoeff(r5_2,58,1);  SetCoeff(r5_2,56,1);  SetCoeff(r5_2,54,1);  SetCoeff(r5_2,53,1);  
SetCoeff(r5_2,51,1);  SetCoeff(r5_2,49,1);  SetCoeff(r5_2,48,1);  SetCoeff(r5_2,47,1);  SetCoeff(r5_2,42,1);  SetCoeff(r5_2,41,1);  SetCoeff(r5_2,39,1);  SetCoeff(r5_2,37,1);  
SetCoeff(r5_2,36,1);  SetCoeff(r5_2,35,1);  SetCoeff(r5_2,33,1);  SetCoeff(r5_2,32,1);  SetCoeff(r5_2,26,1);  SetCoeff(r5_2,24,1);  SetCoeff(r5_2,22,1);  SetCoeff(r5_2,20,1);  
SetCoeff(r5_2,19,1);  SetCoeff(r5_2,18,1);  SetCoeff(r5_2,14,1);  SetCoeff(r5_2,13,1);  SetCoeff(r5_2,9,1);  SetCoeff(r5_2,8,1);  SetCoeff(r5_2,7,1);  SetCoeff(r5_2,5,1);  
SetCoeff(r5_2,2,1);  SetCoeff(r5_2,0,1);
GF2E r5_2_ = conv<GF2E>(r5_2);


GF2X r5_3;
SetCoeff(r5_3,61,1);  SetCoeff(r5_3,60,1);  SetCoeff(r5_3,56,1);  SetCoeff(r5_3,55,1);  SetCoeff(r5_3,54,1);  SetCoeff(r5_3,53,1);  SetCoeff(r5_3,52,1);  SetCoeff(r5_3,51,1);  
SetCoeff(r5_3,47,1);  SetCoeff(r5_3,42,1);  SetCoeff(r5_3,41,1);  SetCoeff(r5_3,40,1);  SetCoeff(r5_3,37,1);  SetCoeff(r5_3,36,1);  SetCoeff(r5_3,35,1);  SetCoeff(r5_3,33,1);  
SetCoeff(r5_3,29,1);  SetCoeff(r5_3,28,1);  SetCoeff(r5_3,27,1);  SetCoeff(r5_3,24,1);  SetCoeff(r5_3,23,1);  SetCoeff(r5_3,21,1);  SetCoeff(r5_3,20,1);  SetCoeff(r5_3,18,1);  
SetCoeff(r5_3,16,1);  SetCoeff(r5_3,15,1);  SetCoeff(r5_3,12,1);  SetCoeff(r5_3,11,1);  SetCoeff(r5_3,8,1);  SetCoeff(r5_3,6,1);  SetCoeff(r5_3,4,1);  SetCoeff(r5_3,2,1); 
SetCoeff(r5_3,1,1); SetCoeff(r5_3,0,1);
GF2E r5_3_ = conv<GF2E>(r5_3);


GF2X r5_4;
SetCoeff(r5_4,62,1);  SetCoeff(r5_4,60,1);  SetCoeff(r5_4,57,1);  SetCoeff(r5_4,56,1);  SetCoeff(r5_4,55,1);  SetCoeff(r5_4,54,1);  SetCoeff(r5_4,53,1);  SetCoeff(r5_4,49,1);  
SetCoeff(r5_4,48,1);  SetCoeff(r5_4,46,1);  SetCoeff(r5_4,45,1);  SetCoeff(r5_4,42,1);  SetCoeff(r5_4,40,1);  SetCoeff(r5_4,39,1);  SetCoeff(r5_4,34,1);  SetCoeff(r5_4,33,1);  
SetCoeff(r5_4,31,1);  SetCoeff(r5_4,25,1);  SetCoeff(r5_4,24,1);  SetCoeff(r5_4,23,1);  SetCoeff(r5_4,21,1);  SetCoeff(r5_4,19,1);  SetCoeff(r5_4,17,1);  SetCoeff(r5_4,14,1);  
SetCoeff(r5_4,13,1);  SetCoeff(r5_4,11,1);  SetCoeff(r5_4,10,1);  SetCoeff(r5_4,9,1);  
SetCoeff(r5_4,4,1);
GF2E r5_4_ = conv<GF2E>(r5_4);


GF2X r5_5;
SetCoeff(r5_5,61,1);  SetCoeff(r5_5,59,1);  SetCoeff(r5_5,58,1);  SetCoeff(r5_5,57,1);  SetCoeff(r5_5,56,1);  SetCoeff(r5_5,54,1);  SetCoeff(r5_5,53,1);  SetCoeff(r5_5,51,1);  
SetCoeff(r5_5,50,1);  SetCoeff(r5_5,46,1);  SetCoeff(r5_5,42,1);  SetCoeff(r5_5,41,1);  SetCoeff(r5_5,40,1);  SetCoeff(r5_5,39,1);  SetCoeff(r5_5,38,1);  SetCoeff(r5_5,37,1);  
SetCoeff(r5_5,35,1);  SetCoeff(r5_5,34,1);  SetCoeff(r5_5,32,1);  SetCoeff(r5_5,31,1);  SetCoeff(r5_5,29,1);  SetCoeff(r5_5,27,1);  SetCoeff(r5_5,26,1);  SetCoeff(r5_5,25,1);  
SetCoeff(r5_5,22,1);  SetCoeff(r5_5,20,1);  SetCoeff(r5_5,19,1);  SetCoeff(r5_5,17,1);  SetCoeff(r5_5,13,1);  SetCoeff(r5_5,5,1);  SetCoeff(r5_5,3,1);  SetCoeff(r5_5,2,1);  
SetCoeff(r5_5,1,1);   SetCoeff(r5_5,0,1);
GF2E r5_5_ = conv<GF2E>(r5_5);


GF2X r5_6;
SetCoeff(r5_6,62,1);  SetCoeff(r5_6,53,1);  SetCoeff(r5_6,50,1);  SetCoeff(r5_6,48,1);  SetCoeff(r5_6,47,1);  SetCoeff(r5_6,46,1);  SetCoeff(r5_6,44,1);  SetCoeff(r5_6,42,1);  
SetCoeff(r5_6,41,1);  SetCoeff(r5_6,40,1);  SetCoeff(r5_6,38,1);  SetCoeff(r5_6,36,1);  SetCoeff(r5_6,34,1);  SetCoeff(r5_6,25,1);  SetCoeff(r5_6,24,1);  SetCoeff(r5_6,22,1);  
SetCoeff(r5_6,20,1);  SetCoeff(r5_6,19,1);  SetCoeff(r5_6,18,1);  SetCoeff(r5_6,16,1);  SetCoeff(r5_6,11,1);  SetCoeff(r5_6,10,1);  SetCoeff(r5_6,9,1);  SetCoeff(r5_6,8,1);  
SetCoeff(r5_6,7,1);  SetCoeff(r5_6,5,1);  SetCoeff(r5_6,3,1);  SetCoeff(r5_6,1,1);
GF2E r5_6_ = conv<GF2E>(r5_6);


//Round 6
GF2X r6_1;
SetCoeff(r6_1,62,1);  SetCoeff(r6_1,59,1);  SetCoeff(r6_1,57,1);  SetCoeff(r6_1,54,1);  SetCoeff(r6_1,51,1);  SetCoeff(r6_1,47,1);  SetCoeff(r6_1,46,1);  SetCoeff(r6_1,44,1);  
SetCoeff(r6_1,43,1);  SetCoeff(r6_1,41,1);  SetCoeff(r6_1,40,1);  SetCoeff(r6_1,39,1);  SetCoeff(r6_1,38,1);  SetCoeff(r6_1,36,1);  SetCoeff(r6_1,31,1);  SetCoeff(r6_1,29,1);  
SetCoeff(r6_1,27,1);  SetCoeff(r6_1,26,1);  SetCoeff(r6_1,25,1);  SetCoeff(r6_1,23,1);  SetCoeff(r6_1,22,1);  SetCoeff(r6_1,21,1);  SetCoeff(r6_1,19,1);  SetCoeff(r6_1,15,1);  
SetCoeff(r6_1,13,1);  SetCoeff(r6_1,10,1);  SetCoeff(r6_1,9,1);  SetCoeff(r6_1,8,1);  
SetCoeff(r6_1,6,1);  SetCoeff(r6_1,5,1);  SetCoeff(r6_1,4,1);  SetCoeff(r6_1,3,1);  
SetCoeff(r6_1,2,1); SetCoeff(r6_1,1,1);
GF2E r6_1_ = conv<GF2E>(r6_1);


GF2X r6_2;
SetCoeff(r6_2,61,1);  SetCoeff(r6_2,60,1);  SetCoeff(r6_2,59,1);  SetCoeff(r6_2,52,1);  SetCoeff(r6_2,49,1);  SetCoeff(r6_2,48,1);  SetCoeff(r6_2,42,1);  SetCoeff(r6_2,40,1);  
SetCoeff(r6_2,36,1);  SetCoeff(r6_2,31,1);  SetCoeff(r6_2,22,1);  SetCoeff(r6_2,21,1);  SetCoeff(r6_2,20,1);  SetCoeff(r6_2,19,1);  SetCoeff(r6_2,18,1);  SetCoeff(r6_2,16,1);  
SetCoeff(r6_2,15,1);  SetCoeff(r6_2,14,1);  SetCoeff(r6_2,12,1);  SetCoeff(r6_2,10,1);  SetCoeff(r6_2,9,1);  SetCoeff(r6_2,4,1);  SetCoeff(r6_2,2,1); SetCoeff(r6_2,1,1); 
SetCoeff(r6_2,0,1);
GF2E r6_2_ = conv<GF2E>(r6_2);


GF2X r6_3;
SetCoeff(r6_3,60,1);  SetCoeff(r6_3,59,1);  SetCoeff(r6_3,56,1);  SetCoeff(r6_3,53,1);  SetCoeff(r6_3,50,1);  SetCoeff(r6_3,47,1);  SetCoeff(r6_3,46,1);  SetCoeff(r6_3,42,1);  
SetCoeff(r6_3,41,1);  SetCoeff(r6_3,36,1);  SetCoeff(r6_3,35,1);  SetCoeff(r6_3,28,1);  SetCoeff(r6_3,26,1);  SetCoeff(r6_3,19,1);  SetCoeff(r6_3,15,1);  SetCoeff(r6_3,13,1);  
SetCoeff(r6_3,12,1);  SetCoeff(r6_3,11,1);  SetCoeff(r6_3,10,1);  SetCoeff(r6_3,8,1);  
SetCoeff(r6_3,5,1);  SetCoeff(r6_3,2,1);
GF2E r6_3_ = conv<GF2E>(r6_3);


GF2X r6_4;
SetCoeff(r6_4,62,1);  SetCoeff(r6_4,59,1);  SetCoeff(r6_4,58,1);  SetCoeff(r6_4,56,1);  SetCoeff(r6_4,55,1);  SetCoeff(r6_4,54,1);  SetCoeff(r6_4,51,1);  SetCoeff(r6_4,46,1);  
SetCoeff(r6_4,43,1);  SetCoeff(r6_4,42,1);  SetCoeff(r6_4,40,1);  SetCoeff(r6_4,39,1);  SetCoeff(r6_4,38,1);  SetCoeff(r6_4,37,1);  SetCoeff(r6_4,33,1);  SetCoeff(r6_4,31,1);  
SetCoeff(r6_4,28,1);  SetCoeff(r6_4,27,1);  SetCoeff(r6_4,25,1);  SetCoeff(r6_4,24,1);  SetCoeff(r6_4,23,1);  SetCoeff(r6_4,22,1);  SetCoeff(r6_4,21,1);  SetCoeff(r6_4,20,1);  
SetCoeff(r6_4,19,1);  SetCoeff(r6_4,17,1);  SetCoeff(r6_4,16,1);  SetCoeff(r6_4,14,1);  SetCoeff(r6_4,13,1);  SetCoeff(r6_4,12,1);  SetCoeff(r6_4,7,1);  SetCoeff(r6_4,6,1);  
SetCoeff(r6_4,4,1);  SetCoeff(r6_4,0,1);
GF2E r6_4_ = conv<GF2E>(r6_4);


GF2X r6_5;
SetCoeff(r6_5,59,1);  SetCoeff(r6_5,57,1);  SetCoeff(r6_5,54,1);  SetCoeff(r6_5,49,1);  SetCoeff(r6_5,47,1);  SetCoeff(r6_5,46,1);  SetCoeff(r6_5,45,1);  SetCoeff(r6_5,44,1);  
SetCoeff(r6_5,41,1);  SetCoeff(r6_5,29,1);  SetCoeff(r6_5,26,1);  SetCoeff(r6_5,22,1);  SetCoeff(r6_5,13,1);  SetCoeff(r6_5,11,1);  SetCoeff(r6_5,9,1);  SetCoeff(r6_5,7,1);  
SetCoeff(r6_5,6,1);  SetCoeff(r6_5,5,1);  SetCoeff(r6_5,4,1);  SetCoeff(r6_5,3,1);  
SetCoeff(r6_5,2,1); SetCoeff(r6_5,1,1); SetCoeff(r6_5,0,1);
GF2E r6_5_ = conv<GF2E>(r6_5);


GF2X r6_6;
SetCoeff(r6_6,62,1);  SetCoeff(r6_6,61,1);  SetCoeff(r6_6,60,1);  SetCoeff(r6_6,59,1);  SetCoeff(r6_6,58,1);  SetCoeff(r6_6,55,1);  SetCoeff(r6_6,54,1);  SetCoeff(r6_6,53,1);  
SetCoeff(r6_6,49,1);  SetCoeff(r6_6,43,1);  SetCoeff(r6_6,36,1);  SetCoeff(r6_6,35,1);  SetCoeff(r6_6,34,1);  SetCoeff(r6_6,33,1);  SetCoeff(r6_6,32,1);  SetCoeff(r6_6,31,1);  
SetCoeff(r6_6,30,1);  SetCoeff(r6_6,28,1);  SetCoeff(r6_6,26,1);  SetCoeff(r6_6,25,1);  SetCoeff(r6_6,24,1);  SetCoeff(r6_6,21,1);  SetCoeff(r6_6,18,1);  SetCoeff(r6_6,15,1);  
SetCoeff(r6_6,12,1);  SetCoeff(r6_6,11,1);  SetCoeff(r6_6,10,1);  SetCoeff(r6_6,8,1);  
SetCoeff(r6_6,7,1);  SetCoeff(r6_6,6,1);  SetCoeff(r6_6,5,1);  SetCoeff(r6_6,3,1); 
SetCoeff(r6_6,1,1);  SetCoeff(r6_6,0,1);
GF2E r6_6_ = conv<GF2E>(r6_6);


//Round 7
GF2X r7_1;
SetCoeff(r7_1,62,1);  SetCoeff(r7_1,61,1);  SetCoeff(r7_1,57,1);  SetCoeff(r7_1,55,1);  SetCoeff(r7_1,51,1);  SetCoeff(r7_1,50,1);  SetCoeff(r7_1,49,1);  SetCoeff(r7_1,48,1);  
SetCoeff(r7_1,47,1);  SetCoeff(r7_1,46,1);  SetCoeff(r7_1,45,1);  SetCoeff(r7_1,44,1);  SetCoeff(r7_1,39,1);  SetCoeff(r7_1,38,1);  SetCoeff(r7_1,37,1);  SetCoeff(r7_1,36,1);  
SetCoeff(r7_1,35,1);  SetCoeff(r7_1,34,1);  SetCoeff(r7_1,33,1);  SetCoeff(r7_1,32,1);  SetCoeff(r7_1,30,1);  SetCoeff(r7_1,27,1);  SetCoeff(r7_1,24,1);  SetCoeff(r7_1,23,1);  
SetCoeff(r7_1,22,1);  SetCoeff(r7_1,19,1);  SetCoeff(r7_1,17,1);  SetCoeff(r7_1,15,1);  SetCoeff(r7_1,14,1);  SetCoeff(r7_1,12,1);  SetCoeff(r7_1,10,1);  SetCoeff(r7_1,7,1);  
SetCoeff(r7_1,6,1);  SetCoeff(r7_1,5,1);  SetCoeff(r7_1,3,1);
GF2E r7_1_ = conv<GF2E>(r7_1);


GF2X r7_2;
SetCoeff(r7_2,62,1);  SetCoeff(r7_2,60,1);  SetCoeff(r7_2,59,1);  SetCoeff(r7_2,58,1);  SetCoeff(r7_2,57,1);  SetCoeff(r7_2,55,1);  SetCoeff(r7_2,54,1);  SetCoeff(r7_2,52,1);  
SetCoeff(r7_2,50,1);  SetCoeff(r7_2,47,1);  SetCoeff(r7_2,45,1);  SetCoeff(r7_2,44,1);  SetCoeff(r7_2,41,1);  SetCoeff(r7_2,39,1);  SetCoeff(r7_2,38,1);  SetCoeff(r7_2,36,1);  
SetCoeff(r7_2,35,1);  SetCoeff(r7_2,31,1);  SetCoeff(r7_2,29,1);  SetCoeff(r7_2,28,1);  SetCoeff(r7_2,23,1);  SetCoeff(r7_2,22,1);  SetCoeff(r7_2,19,1);  SetCoeff(r7_2,17,1);  
SetCoeff(r7_2,16,1);  SetCoeff(r7_2,15,1);  SetCoeff(r7_2,14,1);  SetCoeff(r7_2,12,1);  SetCoeff(r7_2,9,1);  SetCoeff(r7_2,8,1);  SetCoeff(r7_2,4,1);  SetCoeff(r7_2,2,1);  
SetCoeff(r7_2,0,1);
GF2E r7_2_ = conv<GF2E>(r7_2);


GF2X r7_3;
SetCoeff(r7_3,61,1);  SetCoeff(r7_3,60,1);  SetCoeff(r7_3,56,1);  SetCoeff(r7_3,55,1);  SetCoeff(r7_3,52,1);  SetCoeff(r7_3,50,1);  SetCoeff(r7_3,49,1);  SetCoeff(r7_3,46,1);  
SetCoeff(r7_3,44,1);  SetCoeff(r7_3,43,1);  SetCoeff(r7_3,40,1);  SetCoeff(r7_3,39,1);  SetCoeff(r7_3,38,1);  SetCoeff(r7_3,37,1);  SetCoeff(r7_3,36,1);  SetCoeff(r7_3,34,1);  
SetCoeff(r7_3,32,1);  SetCoeff(r7_3,31,1);  SetCoeff(r7_3,28,1);  SetCoeff(r7_3,23,1);  SetCoeff(r7_3,22,1);  SetCoeff(r7_3,21,1);  SetCoeff(r7_3,18,1);  SetCoeff(r7_3,17,1);  
SetCoeff(r7_3,15,1);  SetCoeff(r7_3,14,1);  SetCoeff(r7_3,12,1);  SetCoeff(r7_3,11,1);  SetCoeff(r7_3,10,1);  SetCoeff(r7_3,9,1);  SetCoeff(r7_3,7,1);  SetCoeff(r7_3,6,1);  
SetCoeff(r7_3,4,1);  SetCoeff(r7_3,3,1);  SetCoeff(r7_3,2,1);  SetCoeff(r7_3,0,1);
GF2E r7_3_ = conv<GF2E>(r7_3);


GF2X r7_4;
SetCoeff(r7_4,59,1);  SetCoeff(r7_4,57,1);  SetCoeff(r7_4,56,1);  SetCoeff(r7_4,55,1);  SetCoeff(r7_4,54,1);  SetCoeff(r7_4,53,1);  SetCoeff(r7_4,52,1);  SetCoeff(r7_4,49,1);  
SetCoeff(r7_4,47,1);  SetCoeff(r7_4,45,1);  SetCoeff(r7_4,41,1);  SetCoeff(r7_4,39,1);  SetCoeff(r7_4,38,1);  SetCoeff(r7_4,37,1);  SetCoeff(r7_4,35,1);  SetCoeff(r7_4,34,1);  
SetCoeff(r7_4,31,1);  SetCoeff(r7_4,30,1);  SetCoeff(r7_4,26,1);  SetCoeff(r7_4,25,1);  SetCoeff(r7_4,21,1);  SetCoeff(r7_4,20,1);  SetCoeff(r7_4,19,1);  SetCoeff(r7_4,18,1);  
SetCoeff(r7_4,11,1);  SetCoeff(r7_4,10,1);  SetCoeff(r7_4,9,1);  SetCoeff(r7_4,8,1);  
SetCoeff(r7_4,7,1);
GF2E r7_4_ = conv<GF2E>(r7_4);


GF2X r7_5;
SetCoeff(r7_5,62,1);  SetCoeff(r7_5,60,1);  SetCoeff(r7_5,58,1);  SetCoeff(r7_5,57,1);  SetCoeff(r7_5,56,1);  SetCoeff(r7_5,54,1);  SetCoeff(r7_5,51,1);  SetCoeff(r7_5,47,1);  
SetCoeff(r7_5,43,1);  SetCoeff(r7_5,42,1);  SetCoeff(r7_5,41,1);  SetCoeff(r7_5,38,1);  SetCoeff(r7_5,36,1);  SetCoeff(r7_5,32,1);  SetCoeff(r7_5,31,1);  SetCoeff(r7_5,29,1);  
SetCoeff(r7_5,28,1);  SetCoeff(r7_5,25,1);  SetCoeff(r7_5,22,1);  SetCoeff(r7_5,15,1);  SetCoeff(r7_5,14,1);  SetCoeff(r7_5,7,1);  SetCoeff(r7_5,6,1);  SetCoeff(r7_5,5,1);  
SetCoeff(r7_5,4,1);  SetCoeff(r7_5,3,1);  SetCoeff(r7_5,1,1);
GF2E r7_5_ = conv<GF2E>(r7_5);


GF2X r7_6;
SetCoeff(r7_6,61,1);  SetCoeff(r7_6,58,1);  SetCoeff(r7_6,57,1);  SetCoeff(r7_6,56,1);  SetCoeff(r7_6,55,1);  SetCoeff(r7_6,54,1);  SetCoeff(r7_6,52,1);  SetCoeff(r7_6,51,1);  
SetCoeff(r7_6,49,1);  SetCoeff(r7_6,48,1);  SetCoeff(r7_6,46,1);  SetCoeff(r7_6,37,1);  SetCoeff(r7_6,31,1);  SetCoeff(r7_6,27,1);  SetCoeff(r7_6,26,1);  SetCoeff(r7_6,23,1);  
SetCoeff(r7_6,22,1);  SetCoeff(r7_6,20,1);  SetCoeff(r7_6,19,1);  SetCoeff(r7_6,17,1);  SetCoeff(r7_6,14,1);  SetCoeff(r7_6,13,1);  SetCoeff(r7_6,9,1);  SetCoeff(r7_6,8,1);  
SetCoeff(r7_6,7,1);  SetCoeff(r7_6,6,1);  SetCoeff(r7_6,4,1); SetCoeff(r7_6,1,1); 
SetCoeff(r7_6,0,1);
GF2E r7_6_ = conv<GF2E>(r7_6);


//Round 8
GF2X r8_1;
SetCoeff(r8_1,61,1);  SetCoeff(r8_1,58,1);  SetCoeff(r8_1,45,1);  SetCoeff(r8_1,41,1);  SetCoeff(r8_1,36,1);  SetCoeff(r8_1,34,1);  SetCoeff(r8_1,33,1);  SetCoeff(r8_1,30,1);  
SetCoeff(r8_1,29,1);  SetCoeff(r8_1,27,1);  SetCoeff(r8_1,26,1);  SetCoeff(r8_1,25,1);  SetCoeff(r8_1,24,1);  SetCoeff(r8_1,19,1);  SetCoeff(r8_1,18,1);  SetCoeff(r8_1,16,1);  
SetCoeff(r8_1,15,1);  SetCoeff(r8_1,14,1);  SetCoeff(r8_1,11,1);  SetCoeff(r8_1,10,1);  SetCoeff(r8_1,8,1);  SetCoeff(r8_1,6,1);  SetCoeff(r8_1,4,1);  SetCoeff(r8_1,0,1);
GF2E r8_1_ = conv<GF2E>(r8_1);


GF2X r8_2;
SetCoeff(r8_2,62,1);  SetCoeff(r8_2,61,1);  SetCoeff(r8_2,59,1);  SetCoeff(r8_2,57,1);  SetCoeff(r8_2,56,1);  SetCoeff(r8_2,55,1);  SetCoeff(r8_2,53,1);  SetCoeff(r8_2,46,1);  
SetCoeff(r8_2,42,1);  SetCoeff(r8_2,40,1);  SetCoeff(r8_2,39,1);  SetCoeff(r8_2,38,1);  SetCoeff(r8_2,34,1);  SetCoeff(r8_2,32,1);  SetCoeff(r8_2,29,1);  SetCoeff(r8_2,28,1);  
SetCoeff(r8_2,27,1);  SetCoeff(r8_2,24,1);  SetCoeff(r8_2,21,1);  SetCoeff(r8_2,20,1);  SetCoeff(r8_2,19,1);  SetCoeff(r8_2,18,1);  SetCoeff(r8_2,17,1);  SetCoeff(r8_2,16,1);  
SetCoeff(r8_2,15,1);  SetCoeff(r8_2,12,1);  SetCoeff(r8_2,11,1);  SetCoeff(r8_2,10,1);  SetCoeff(r8_2,9,1);  SetCoeff(r8_2,8,1);  SetCoeff(r8_2,5,1);  SetCoeff(r8_2,4,1); 
SetCoeff(r8_2,3,1);  SetCoeff(r8_2,2,1);
GF2E r8_2_ = conv<GF2E>(r8_2);


GF2X r8_3;
SetCoeff(r8_3,62,1);  SetCoeff(r8_3,61,1);  SetCoeff(r8_3,60,1);  SetCoeff(r8_3,56,1);  SetCoeff(r8_3,52,1);  SetCoeff(r8_3,49,1);  SetCoeff(r8_3,48,1);  SetCoeff(r8_3,47,1);  
SetCoeff(r8_3,46,1);  SetCoeff(r8_3,44,1);  SetCoeff(r8_3,43,1);  SetCoeff(r8_3,40,1);  SetCoeff(r8_3,39,1);  SetCoeff(r8_3,37,1);  SetCoeff(r8_3,33,1);  SetCoeff(r8_3,32,1);  
SetCoeff(r8_3,28,1);  SetCoeff(r8_3,26,1);  SetCoeff(r8_3,25,1);  SetCoeff(r8_3,24,1);  SetCoeff(r8_3,23,1);  SetCoeff(r8_3,20,1);  SetCoeff(r8_3,16,1);  SetCoeff(r8_3,15,1);  
SetCoeff(r8_3,11,1);  SetCoeff(r8_3,9,1);  SetCoeff(r8_3,7,1);  SetCoeff(r8_3,6,1);  
SetCoeff(r8_3,5,1);  SetCoeff(r8_3,2,1); SetCoeff(r8_3,1,1); SetCoeff(r8_3,0,1);
GF2E r8_3_ = conv<GF2E>(r8_3);


GF2X r8_4;
SetCoeff(r8_4,58,1);  SetCoeff(r8_4,57,1);  SetCoeff(r8_4,56,1);  SetCoeff(r8_4,54,1);  SetCoeff(r8_4,53,1);  SetCoeff(r8_4,52,1);  SetCoeff(r8_4,51,1);  SetCoeff(r8_4,47,1);  
SetCoeff(r8_4,46,1);  SetCoeff(r8_4,43,1);  SetCoeff(r8_4,41,1);  SetCoeff(r8_4,37,1);  SetCoeff(r8_4,36,1);  SetCoeff(r8_4,34,1);  SetCoeff(r8_4,30,1);  SetCoeff(r8_4,29,1);  
SetCoeff(r8_4,28,1);  SetCoeff(r8_4,27,1);  SetCoeff(r8_4,26,1);  SetCoeff(r8_4,25,1);  SetCoeff(r8_4,24,1);  SetCoeff(r8_4,23,1);  SetCoeff(r8_4,19,1);  SetCoeff(r8_4,17,1);  
SetCoeff(r8_4,15,1);  SetCoeff(r8_4,14,1);  SetCoeff(r8_4,11,1);  SetCoeff(r8_4,9,1);  
SetCoeff(r8_4,2,1);  SetCoeff(r8_4,1,1);
GF2E r8_4_ = conv<GF2E>(r8_4);


GF2X r8_5;
SetCoeff(r8_5,62,1);  SetCoeff(r8_5,59,1);  SetCoeff(r8_5,56,1);  SetCoeff(r8_5,54,1);  SetCoeff(r8_5,53,1);  SetCoeff(r8_5,50,1);  SetCoeff(r8_5,49,1);  SetCoeff(r8_5,48,1);  
SetCoeff(r8_5,47,1);  SetCoeff(r8_5,46,1);  SetCoeff(r8_5,45,1);  SetCoeff(r8_5,44,1);  SetCoeff(r8_5,43,1);  SetCoeff(r8_5,39,1);  SetCoeff(r8_5,38,1);  SetCoeff(r8_5,35,1);  
SetCoeff(r8_5,34,1);  SetCoeff(r8_5,33,1);  SetCoeff(r8_5,31,1);  SetCoeff(r8_5,30,1);  SetCoeff(r8_5,29,1);  SetCoeff(r8_5,28,1);  SetCoeff(r8_5,20,1);  SetCoeff(r8_5,18,1);  
SetCoeff(r8_5,14,1);  SetCoeff(r8_5,11,1);  SetCoeff(r8_5,8,1);  SetCoeff(r8_5,2,1); 
SetCoeff(r8_5,1,1); SetCoeff(r8_5,0,1);
GF2E r8_5_ = conv<GF2E>(r8_5);


GF2X r8_6;
SetCoeff(r8_6,61,1);  SetCoeff(r8_6,60,1);  SetCoeff(r8_6,59,1);  SetCoeff(r8_6,58,1);  SetCoeff(r8_6,57,1);  SetCoeff(r8_6,55,1);  SetCoeff(r8_6,51,1);  SetCoeff(r8_6,48,1);  
SetCoeff(r8_6,47,1);  SetCoeff(r8_6,43,1);  SetCoeff(r8_6,39,1);  SetCoeff(r8_6,38,1);  SetCoeff(r8_6,37,1);  SetCoeff(r8_6,34,1);  SetCoeff(r8_6,33,1);  SetCoeff(r8_6,28,1);  
SetCoeff(r8_6,24,1);  SetCoeff(r8_6,22,1);  SetCoeff(r8_6,21,1);  SetCoeff(r8_6,20,1);  SetCoeff(r8_6,19,1);  SetCoeff(r8_6,18,1);  SetCoeff(r8_6,17,1);  SetCoeff(r8_6,14,1);  
SetCoeff(r8_6,13,1);  SetCoeff(r8_6,11,1);  SetCoeff(r8_6,9,1);  SetCoeff(r8_6,8,1);  
SetCoeff(r8_6,7,1);  SetCoeff(r8_6,6,1);  SetCoeff(r8_6,4,1);  SetCoeff(r8_6,3,1); 
SetCoeff(r8_6,1,1); SetCoeff(r8_6,0,1);
GF2E r8_6_ = conv<GF2E>(r8_6);


GF2E consts[48] = {
  r1_1_, r1_2_, r1_3_, r1_4_, r1_5_, r1_6_, r2_1_, r2_2_, r2_3_, r2_4_, r2_5_, r2_6_, r3_1_, r3_2_,
  r3_3_, r3_4_, r3_5_, r3_6_, r4_1_, r4_2_, r4_3_, r4_4_, r4_5_, r4_6_, r5_1_, r5_2_, r5_3_, r5_4_,
  r5_5_, r5_6_, r6_1_, r6_2_, r6_3_, r6_4_, r6_5_, r6_6_, r7_1_, r7_2_, r7_3_, r7_4_, r7_5_, r7_6_,
  r8_1_, r8_2_, r8_3_, r8_4_, r8_5_, r8_6_
};

GF2X r0_1;
SetCoeff(r0_1,62,1);  SetCoeff(r0_1,61,1);  SetCoeff(r0_1,58,1);  SetCoeff(r0_1,57,1);  SetCoeff(r0_1,54,1);  SetCoeff(r0_1,52,1);  SetCoeff(r0_1,51,1);  SetCoeff(r0_1,49,1);  
SetCoeff(r0_1,48,1);  SetCoeff(r0_1,45,1);  SetCoeff(r0_1,44,1);  SetCoeff(r0_1,42,1);  SetCoeff(r0_1,41,1);  SetCoeff(r0_1,38,1);  SetCoeff(r0_1,37,1);  SetCoeff(r0_1,36,1);  
SetCoeff(r0_1,35,1);  SetCoeff(r0_1,32,1);  SetCoeff(r0_1,31,1);  SetCoeff(r0_1,30,1);  SetCoeff(r0_1,29,1);  SetCoeff(r0_1,28,1);  SetCoeff(r0_1,26,1);  SetCoeff(r0_1,21,1);  
SetCoeff(r0_1,20,1);  SetCoeff(r0_1,17,1);  SetCoeff(r0_1,16,1);  SetCoeff(r0_1,14,1);  
SetCoeff(r0_1,12,1);  SetCoeff(r0_1,11,1);  SetCoeff(r0_1,10,1);  SetCoeff(r0_1,9,1); 
SetCoeff(r0_1,8,1); SetCoeff(r0_1,6,1); SetCoeff(r0_1,5,1); SetCoeff(r0_1,0,1);
GF2E r0_1_ = conv<GF2E>(r0_1);

GF2X r0_2;
SetCoeff(r0_2,62,1); SetCoeff(r0_2,59,1); SetCoeff(r0_2,58,1); SetCoeff(r0_2,57,1); SetCoeff(r0_2,56,1); SetCoeff(r0_2,54,1); SetCoeff(r0_2,53,1); SetCoeff(r0_2,48,1); SetCoeff(r0_2,44,1); SetCoeff(r0_2,41,1); SetCoeff(r0_2,38,1); SetCoeff(r0_2,37,1); SetCoeff(r0_2,34,1); SetCoeff(r0_2,33,1); SetCoeff(r0_2,32,1); SetCoeff(r0_2,29,1); SetCoeff(r0_2,28,1); SetCoeff(r0_2,26,1); SetCoeff(r0_2,21,1); SetCoeff(r0_2,20,1); SetCoeff(r0_2,19,1); SetCoeff(r0_2,18,1); SetCoeff(r0_2,16,1); SetCoeff(r0_2,15,1); SetCoeff(r0_2,14,1); SetCoeff(r0_2,13,1); SetCoeff(r0_2,9,1); SetCoeff(r0_2,7,1); SetCoeff(r0_2,6,1); SetCoeff(r0_2,5,1); SetCoeff(r0_2,4,1); SetCoeff(r0_2,0,1);
GF2E r0_2_ = conv<GF2E>(r0_2);

GF2X r0_3;
SetCoeff(r0_3,59,1); SetCoeff(r0_3,58,1); SetCoeff(r0_3,55,1); SetCoeff(r0_3,54,1); SetCoeff(r0_3,51,1); SetCoeff(r0_3,49,1); SetCoeff(r0_3,47,1); SetCoeff(r0_3,46,1); SetCoeff(r0_3,43,1); SetCoeff(r0_3,38,1); SetCoeff(r0_3,37,1); SetCoeff(r0_3,36,1); SetCoeff(r0_3,34,1); SetCoeff(r0_3,32,1); SetCoeff(r0_3,31,1); SetCoeff(r0_3,29,1); SetCoeff(r0_3,28,1); SetCoeff(r0_3,24,1); SetCoeff(r0_3,23,1); SetCoeff(r0_3,20,1); SetCoeff(r0_3,19,1); SetCoeff(r0_3,16,1); SetCoeff(r0_3,13,1); SetCoeff(r0_3,12,1); SetCoeff(r0_3,11,1); SetCoeff(r0_3,9,1); SetCoeff(r0_3,8,1); SetCoeff(r0_3,5,1); SetCoeff(r0_3,2,1); SetCoeff(r0_3,1,1); SetCoeff(r0_3,0,1);
GF2E r0_3_ = conv<GF2E>(r0_3);

GF2X r9_1;
SetCoeff(r9_1,62,1); SetCoeff(r9_1,61,1); SetCoeff(r9_1,56,1); SetCoeff(r9_1,52,1); SetCoeff(r9_1,51,1); SetCoeff(r9_1,50,1); SetCoeff(r9_1,44,1); SetCoeff(r9_1,42,1); SetCoeff(r9_1,40,1); SetCoeff(r9_1,39,1); SetCoeff(r9_1,38,1); SetCoeff(r9_1,35,1); SetCoeff(r9_1,33,1); SetCoeff(r9_1,31,1); SetCoeff(r9_1,30,1); SetCoeff(r9_1,26,1); SetCoeff(r9_1,24,1); SetCoeff(r9_1,21,1); SetCoeff(r9_1,18,1); SetCoeff(r9_1,17,1); SetCoeff(r9_1,16,1); SetCoeff(r9_1,15,1); SetCoeff(r9_1,10,1); SetCoeff(r9_1,8,1); SetCoeff(r9_1,6,1); SetCoeff(r9_1,3,1); SetCoeff(r9_1,2,1); SetCoeff(r9_1,1,1);
GF2E r9_1_ = conv<GF2E>(r9_1);

GF2X r9_2;
SetCoeff(r9_2,62,1); SetCoeff(r9_2,58,1); SetCoeff(r9_2,56,1); SetCoeff(r9_2,55,1); SetCoeff(r9_2,54,1); SetCoeff(r9_2,51,1); SetCoeff(r9_2,49,1); SetCoeff(r9_2,48,1); SetCoeff(r9_2,47,1); SetCoeff(r9_2,39,1); SetCoeff(r9_2,37,1); SetCoeff(r9_2,34,1); SetCoeff(r9_2,32,1); SetCoeff(r9_2,31,1); SetCoeff(r9_2,29,1); SetCoeff(r9_2,28,1); SetCoeff(r9_2,27,1); SetCoeff(r9_2,26,1); SetCoeff(r9_2,22,1); SetCoeff(r9_2,20,1); SetCoeff(r9_2,19,1); SetCoeff(r9_2,18,1); SetCoeff(r9_2,17,1); SetCoeff(r9_2,15,1); SetCoeff(r9_2,13,1); SetCoeff(r9_2,10,1); SetCoeff(r9_2,8,1); SetCoeff(r9_2,4,1); SetCoeff(r9_2,3,1); SetCoeff(r9_2,2,1);
GF2E r9_2_ = conv<GF2E>(r9_2);

GF2X r9_3;
SetCoeff(r9_3,62,1); SetCoeff(r9_3,59,1); SetCoeff(r9_3,54,1); SetCoeff(r9_3,49,1); SetCoeff(r9_3,45,1); SetCoeff(r9_3,41,1); SetCoeff(r9_3,40,1); SetCoeff(r9_3,39,1); SetCoeff(r9_3,37,1); SetCoeff(r9_3,35,1); SetCoeff(r9_3,34,1); SetCoeff(r9_3,33,1); SetCoeff(r9_3,32,1); SetCoeff(r9_3,29,1); SetCoeff(r9_3,27,1); SetCoeff(r9_3,25,1); SetCoeff(r9_3,24,1); SetCoeff(r9_3,21,1); SetCoeff(r9_3,18,1); SetCoeff(r9_3,17,1); SetCoeff(r9_3,14,1); SetCoeff(r9_3,12,1); SetCoeff(r9_3,11,1); SetCoeff(r9_3,8,1); SetCoeff(r9_3,5,1); SetCoeff(r9_3,2,1);
GF2E r9_3_ = conv<GF2E>(r9_3);

GF2E consts0[3] = {
  r0_1_, r0_2_, r0_3_
};

GF2E consts9[3] = {
  r9_1_, r9_2_, r9_3_
};

/////////////////////c1
GF2X c1;
SetCoeff(c1,60,1); SetCoeff(c1,59,1); SetCoeff(c1,58,1); SetCoeff(c1,56,1); SetCoeff(c1,53,1);
SetCoeff(c1,52,1); SetCoeff(c1,50,1); SetCoeff(c1,48,1); SetCoeff(c1,46,1); SetCoeff(c1,44,1);
SetCoeff(c1,43,1); SetCoeff(c1,40,1); SetCoeff(c1,39,1); SetCoeff(c1,38,1); SetCoeff(c1,37,1);
SetCoeff(c1,35,1); SetCoeff(c1,33,1); SetCoeff(c1,31,1); SetCoeff(c1,28,1); SetCoeff(c1,27,1);
SetCoeff(c1,26,1); SetCoeff(c1,23,1); SetCoeff(c1,21,1); SetCoeff(c1,20,1); SetCoeff(c1,18,1);
SetCoeff(c1,16,1); SetCoeff(c1,15,1); SetCoeff(c1,14,1); SetCoeff(c1,12,1); SetCoeff(c1,10,1);
SetCoeff(c1,9,1); SetCoeff(c1,6,1); SetCoeff(c1,5,1); SetCoeff(c1,2,1); SetCoeff(c1,1,1);
GF2E c1_ = conv<GF2E>(c1);


/////////////////////c2
GF2X c2;
SetCoeff(c2,62,1); SetCoeff(c2,61,1); SetCoeff(c2,60,1); SetCoeff(c2,57,1); SetCoeff(c2,56,1);
SetCoeff(c2,51,1); SetCoeff(c2,50,1); SetCoeff(c2,49,1); SetCoeff(c2,48,1); SetCoeff(c2,46,1);
SetCoeff(c2,45,1); SetCoeff(c2,44,1); SetCoeff(c2,43,1); SetCoeff(c2,40,1); SetCoeff(c2,37,1);
SetCoeff(c2,33,1); SetCoeff(c2,32,1); SetCoeff(c2,31,1); SetCoeff(c2,30,1); SetCoeff(c2,29,1);
SetCoeff(c2,25,1); SetCoeff(c2,22,1); SetCoeff(c2,20,1); SetCoeff(c2,18,1); SetCoeff(c2,17,1);
SetCoeff(c2,15,1); SetCoeff(c2,14,1); SetCoeff(c2,12,1); SetCoeff(c2,11,1); SetCoeff(c2,10,1);
SetCoeff(c2,5,1); SetCoeff(c2,1,1); SetCoeff(c2,0,1); 
GF2E c2_ = conv<GF2E>(c2);


/////////////////////c3
GF2X c3;
SetCoeff(c3,61,1); SetCoeff(c3,59,1); SetCoeff(c3,57,1); SetCoeff(c3,54,1); SetCoeff(c3,53,1);
SetCoeff(c3,52,1); SetCoeff(c3,50,1); SetCoeff(c3,49,1); SetCoeff(c3,48,1); SetCoeff(c3,47,1);
SetCoeff(c3,45,1); SetCoeff(c3,42,1); SetCoeff(c3,40,1); SetCoeff(c3,37,1); SetCoeff(c3,36,1);
SetCoeff(c3,35,1); SetCoeff(c3,34,1); SetCoeff(c3,33,1); SetCoeff(c3,31,1); SetCoeff(c3,29,1);
SetCoeff(c3,26,1); SetCoeff(c3,24,1); SetCoeff(c3,23,1); SetCoeff(c3,21,1); SetCoeff(c3,20,1);
SetCoeff(c3,19,1); SetCoeff(c3,17,1); SetCoeff(c3,14,1); SetCoeff(c3,13,1); SetCoeff(c3,8,1);
SetCoeff(c3,6,1); SetCoeff(c3,4,1); SetCoeff(c3,0,1); 
GF2E c3_ = conv<GF2E>(c3);


/////////////////////c4
GF2X c4;
SetCoeff(c4,59,1); SetCoeff(c4,55,1); SetCoeff(c4,54,1); SetCoeff(c4,53,1); SetCoeff(c4,52,1);
SetCoeff(c4,50,1); SetCoeff(c4,49,1); SetCoeff(c4,46,1); SetCoeff(c4,45,1); SetCoeff(c4,42,1);
SetCoeff(c4,40,1); SetCoeff(c4,38,1); SetCoeff(c4,31,1); SetCoeff(c4,30,1); SetCoeff(c4,26,1);
SetCoeff(c4,24,1); SetCoeff(c4,23,1); SetCoeff(c4,22,1); SetCoeff(c4,19,1); SetCoeff(c4,15,1);
SetCoeff(c4,13,1); SetCoeff(c4,12,1); SetCoeff(c4,7,1); SetCoeff(c4,2,1); SetCoeff(c4,1,1);
GF2E c4_ = conv<GF2E>(c4);


/////////////////////MDS Matrix Constants
GF2X mds1_1;
SetCoeff(mds1_1,6,1); 
GF2E mds1_1_ = conv<GF2E>(mds1_1);

GF2X mds1_2;
SetCoeff(mds1_2,9,1);  SetCoeff(mds1_2,8,1);  SetCoeff(mds1_2,7,1); 
GF2E mds1_2_ = conv<GF2E>(mds1_2);

GF2X mds1_3;
SetCoeff(mds1_3,12,1);  SetCoeff(mds1_3,11,1);  SetCoeff(mds1_3,9,1);  SetCoeff(mds1_3,8,1); 
GF2E mds1_3_ = conv<GF2E>(mds1_3);

GF2X mds2_1;
SetCoeff(mds2_1,5,1);  SetCoeff(mds2_1,4,1);  SetCoeff(mds2_1,3,1); 
GF2E mds2_1_ = conv<GF2E>(mds2_1);

GF2X mds2_2;
SetCoeff(mds2_2,8,1);  SetCoeff(mds2_2,4,1);
GF2E mds2_2_ = conv<GF2E>(mds2_2);

GF2X mds2_3;
SetCoeff(mds2_3,11,1);  SetCoeff(mds2_3,9,1);  SetCoeff(mds2_3,8,1);  SetCoeff(mds2_3,7,1); SetCoeff(mds2_3,5,1);
GF2E mds2_3_ = conv<GF2E>(mds2_3);

GF2X mds3_1;
SetCoeff(mds3_1,3,1);  SetCoeff(mds3_1,2,1);  SetCoeff(mds3_1,1,1);
GF2E mds3_1_ = conv<GF2E>(mds3_1);

GF2X mds3_2;
SetCoeff(mds3_2,6,1);  SetCoeff(mds3_2,5,1);  SetCoeff(mds3_2,3,1);  SetCoeff(mds3_2,2,1);
GF2E mds3_2_ = conv<GF2E>(mds3_2);

GF2X mds3_3;
SetCoeff(mds3_3,9,1);  SetCoeff(mds3_3,8,1);  SetCoeff(mds3_3,4,1);  SetCoeff(mds3_3,3,1);
GF2E mds3_3_ = conv<GF2E>(mds3_3);


  GF2E keys[3] = {conv<GF2E>(key[0]),conv<GF2E>(key[1]),conv<GF2E>(key[1])};
  //Key Addition
  for(int k=0; k<3; k++){
    keys[k]+=consts0[k];
    final_keys[k]=conv<GF2X>(keys[k]);
  }


  for(int i=0; i<8; i++){

    //Non-linear permutation
    for(int k=0; k<3; k++){
      GF2E tmp(keys[k]);
      keys[k] = power(keys[k], 32); 
      keys[k]*=tmp;
    }

    //Affine layer
    for(int k=0; k<3; k++){
      GF2E tmp(keys[k]);
      GF2E tmp2(keys[k]);
      tmp = power(tmp, 8);
      tmp*=c1_;
      tmp2 = power(tmp2, 2);
      tmp2*=c2_;
      keys[k]*=c3_;
      keys[k]+=tmp;
      keys[k]+=tmp2;
      keys[k]+= c4_;
    }

    //Matrix Multiplication
    GF2E tmp(keys[0]);
    GF2E tmp2(keys[1]);
    GF2E tmp3(keys[2]);
    keys[0] = (mds1_1_*tmp)+(mds1_2_*tmp2)+(mds1_3_*tmp3);
    keys[1] = (mds2_1_*tmp)+(mds2_2_*tmp2)+(mds2_3_*tmp3);
    keys[2] = (mds3_1_*tmp)+(mds3_2_*tmp2)+(mds3_3_*tmp3);

    //Key Addition
    for(int k=0; k<3; k++){
      keys[k]+=consts[i*6+k];
      final_keys[i*6+k+3]=conv<GF2X>(keys[k]);
    }

    //Non-linear permutation
    for(int k=0; k<3; k++){
      GF2E tmp(keys[k]);
      keys[k] = power(keys[k], 32); 
      keys[k]*=tmp;
    }

    //Affine layer
    for(int k=0; k<3; k++){
      GF2E tmp(keys[k]);;
      GF2E tmp2(keys[k]);
      tmp = power(tmp, 8);
      tmp*=c1_;
      tmp2 = power(tmp2, 2);
      tmp2*=c2_;
      keys[k]*=c3_;
      keys[k]+=tmp;
      keys[k]+=tmp2;
      keys[k]+= c4_;
    }

    //Matrix Multiplication
    tmp = keys[0];
    tmp2 = keys[1];
    tmp3 = keys[2];
    keys[0] = (mds1_1_*tmp)+(mds1_2_*tmp2)+(mds1_3_*tmp3);
    keys[1] = (mds2_1_*tmp)+(mds2_2_*tmp2)+(mds2_3_*tmp3);
    keys[2] = (mds3_1_*tmp)+(mds3_2_*tmp2)+(mds3_3_*tmp3);

    //Key Addition
    for(int k=0; k<3; k++){
      keys[k]+=consts[i*6+3+k];
      final_keys[i*6+k+6]=conv<GF2X>(keys[k]);
    }
  }

  //Key Addition
  for(int k=0; k<3; k++){
    keys[k]+=consts9[k];
    final_keys[51+k]=conv<GF2X>(keys[k]);
  }
//return final_keys;
}




