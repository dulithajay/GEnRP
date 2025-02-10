#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TTreeReader.h>
#include <TRandom.h>
#include <TApplication.h>
#include <iostream>
#include <vector>
#include <TCanvas.h>
#include <algorithm> // For std::max

void Dulitha_PR_Hodoscope() {

 TChain *T = new TChain("T");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_1.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_2.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_3.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_4.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_5.root");
/*
double sbs_hodoPR_adc_hits_a[10000];   //PRhodoscope FADC all Hits Pulse integral
double sbs_hodoPR_adc_hits_a_amp[10000]; //PRhodoscope FADC all Hits Pulse amplitude
double sbs_hodoPR_adc_hits_a_time[10000];  //PRhodoscope FADC all Hits Pulse Time
double sbs_hodoPR_adc_adcelemID[10000]; //PRhodoscope FADC all good  Hits;Element ID 
double sbs_hodoPR_adc_a_mult[10000];   //PRhodoscope FADC Multiplicity
double sbs_hodoPR_adc_a_p[10000];   //PRhodoscope FADC Pulse Intergral 1D
double sbs_hodoPR_adc_a_amp_p[10000];  //PRhodoscope FADC Amplitude 1D
double sbs_hodoPR_adc_ped[10000];    //PRhodoscope FADC Pedestal 1D
double sbs_hodoPR_adc_nhits[10000];   //PRhodoscope FADC Hits
double sbs_hodoPR_tdc_nhits[10000];  //PRhodoscope TDC Hits
double sbs_hodoPR_tdc_hits_t[10000];   // PRhodoscope TDC all hits Time;time(ns)
double sbs_hodoPR_tdc_hits_TDCelemID[10000];  //PRhodoscope TDC all hits Element ID
*/
double sbs_hodoPR_adc_a[10000];
int Ndata_sbs_hodoPR_adc_a;
double sbs_hodoPR_adc_a_time[10000];
int Ndata_sbs_hodoPR_adc_a_time;
double sbs_hodoPR_adc_adcelemID[10000];
int Ndata_sbs_hodoPR_adc_adcelemID;

double sbs_activeAna_adc_a[10000];
int Ndata_sbs_activeAna_adc_a;
double sbs_activeAna_adc_a_time[10000];
int Ndata_sbs_activeAna_adc_a_time;

double sbs_gemPR_m1_clust_clustu_adc[10000];
double sbs_gemPR_m1_clust_clustv_adc[10000];
double sbs_gemPR_m0_clust_clustu_adc[10000];
double sbs_gemPR_m0_clust_clustv_adc[10000];
double sbs_gemPR_m2_clust_clustu_adc[10000];
double sbs_gemPR_m2_clust_clustv_adc[10000];
double sbs_gemPR_m3_clust_clustu_adc[10000];
double sbs_gemPR_m3_clust_clustv_adc[10000];
double sbs_gemPR_m4_clust_clustu_adc[10000];
double sbs_gemPR_m4_clust_clustv_adc[10000];
double sbs_gemPR_m5_clust_clustu_adc[10000];
double sbs_gemPR_m5_clust_clustv_adc[10000];
double sbs_gemPR_m6_clust_clustu_adc[10000];
double sbs_gemPR_m6_clust_clustv_adc[10000];
double sbs_gemPR_m7_clust_clustu_adc[10000];
double sbs_gemPR_m7_clust_clustv_adc[10000];

int  Ndata_sbs_gemPR_m0_clust_clustu_adc;
int  Ndata_sbs_gemPR_m1_clust_clustu_adc;
int  Ndata_sbs_gemPR_m2_clust_clustu_adc;
int  Ndata_sbs_gemPR_m3_clust_clustu_adc;
int  Ndata_sbs_gemPR_m0_clust_clustv_adc;
int  Ndata_sbs_gemPR_m1_clust_clustv_adc;
int  Ndata_sbs_gemPR_m2_clust_clustv_adc;
int  Ndata_sbs_gemPR_m3_clust_clustv_adc;
int  Ndata_sbs_gemPR_m4_clust_clustu_adc;
int  Ndata_sbs_gemPR_m5_clust_clustu_adc;
int  Ndata_sbs_gemPR_m6_clust_clustu_adc;
int  Ndata_sbs_gemPR_m7_clust_clustu_adc;
int  Ndata_sbs_gemPR_m4_clust_clustv_adc;
int  Ndata_sbs_gemPR_m5_clust_clustv_adc;
int  Ndata_sbs_gemPR_m6_clust_clustv_adc;
int  Ndata_sbs_gemPR_m7_clust_clustv_adc;

//for Layer1
double sbs_gemPR_m1_clust_clustu_time[10000];
double sbs_gemPR_m1_clust_clustv_time[10000];
double sbs_gemPR_m0_clust_clustu_time[10000];
double sbs_gemPR_m0_clust_clustv_time[10000];
double sbs_gemPR_m2_clust_clustu_time[10000];
double sbs_gemPR_m2_clust_clustv_time[10000];
double sbs_gemPR_m3_clust_clustu_time[10000];
double sbs_gemPR_m3_clust_clustv_time[10000];

int Ndata_sbs_gemPR_m1_clust_clustu_time;
int Ndata_sbs_gemPR_m1_clust_clustv_time;
int Ndata_sbs_gemPR_m0_clust_clustu_time;
int Ndata_sbs_gemPR_m0_clust_clustv_time;
int Ndata_sbs_gemPR_m2_clust_clustu_time;
int Ndata_sbs_gemPR_m2_clust_clustv_time;
int Ndata_sbs_gemPR_m3_clust_clustu_time;
int Ndata_sbs_gemPR_m3_clust_clustv_time;


// for Layer2
double sbs_gemPR_m4_clust_clustu_time[10000];
double sbs_gemPR_m4_clust_clustv_time[10000];
double sbs_gemPR_m5_clust_clustu_time[10000];
double sbs_gemPR_m5_clust_clustv_time[10000];
double sbs_gemPR_m6_clust_clustu_time[10000];
double sbs_gemPR_m6_clust_clustv_time[10000];
double sbs_gemPR_m7_clust_clustu_time[10000];
double sbs_gemPR_m7_clust_clustv_time[10000];

int Ndata_sbs_gemPR_m4_clust_clustu_time;
int Ndata_sbs_gemPR_m4_clust_clustv_time;
int Ndata_sbs_gemPR_m5_clust_clustu_time;
int Ndata_sbs_gemPR_m5_clust_clustv_time;
int Ndata_sbs_gemPR_m6_clust_clustu_time;
int Ndata_sbs_gemPR_m6_clust_clustv_time;
int Ndata_sbs_gemPR_m7_clust_clustu_time;
int Ndata_sbs_gemPR_m7_clust_clustv_time;
//For position
double sbs_gemPR_m1_clust_clustu_pos[10000];
double sbs_gemPR_m1_clust_clustv_pos[10000];
double sbs_gemPR_m0_clust_clustu_pos[10000];
double sbs_gemPR_m0_clust_clustv_pos[10000];
double sbs_gemPR_m2_clust_clustu_pos[10000];
double sbs_gemPR_m2_clust_clustv_pos[10000];
double sbs_gemPR_m3_clust_clustu_pos[10000];
double sbs_gemPR_m3_clust_clustv_pos[10000];
int Ndata_sbs_gemPR_m1_clust_clustu_pos;
int Ndata_sbs_gemPR_m1_clust_clustv_pos;
int Ndata_sbs_gemPR_m0_clust_clustu_pos;
int Ndata_sbs_gemPR_m0_clust_clustv_pos;
int Ndata_sbs_gemPR_m2_clust_clustu_pos;
int Ndata_sbs_gemPR_m2_clust_clustv_pos;
int Ndata_sbs_gemPR_m3_clust_clustu_pos;
int Ndata_sbs_gemPR_m3_clust_clustv_pos;
double sbs_gemPR_m4_clust_clustu_pos[10000];
double sbs_gemPR_m4_clust_clustv_pos[10000];
double sbs_gemPR_m5_clust_clustu_pos[10000];
double sbs_gemPR_m5_clust_clustv_pos[10000];
double sbs_gemPR_m6_clust_clustu_pos[10000];
double sbs_gemPR_m6_clust_clustv_pos[10000];
double sbs_gemPR_m7_clust_clustu_pos[10000];
double sbs_gemPR_m7_clust_clustv_pos[10000];
int Ndata_sbs_gemPR_m4_clust_clustu_pos;
int Ndata_sbs_gemPR_m4_clust_clustv_pos;
int Ndata_sbs_gemPR_m5_clust_clustu_pos;
int Ndata_sbs_gemPR_m5_clust_clustv_pos;
int Ndata_sbs_gemPR_m6_clust_clustu_pos;
int Ndata_sbs_gemPR_m6_clust_clustv_pos;
int Ndata_sbs_gemPR_m7_clust_clustu_pos;
int Ndata_sbs_gemPR_m7_clust_clustv_pos;

/*
int Ndata_sbs_hodoPR_adc_hits_a;   //PRhodoscope FADC all Hits Pulse integral
int Ndata_sbs_hodoPR_adc_hits_a_amp; //PRhodoscope FADC all Hits Pulse amplitude
int Ndata_sbs_hodoPR_adc_hits_a_time;  //PRhodoscope FADC all Hits Pulse Time
int Ndata_sbs_hodoPR_adc_adcelemID; //PRhodoscope FADC all good  Hits;Element ID 
int Ndata_sbs_hodoPR_adc_a_mult;   //PRhodoscope FADC Multiplicity
int Ndata_sbs_hodoPR_adc_a_p;   //PRhodoscope FADC Pulse Intergral 1D
int Ndata_sbs_hodoPR_adc_a_amp_p;  //PRhodoscope FADC Amplitude 1D
int Ndata_sbs_hodoPR_adc_ped;    //PRhodoscope FADC Pedestal 1D
int Ndata_sbs_hodoPR_adc_nhits;   //PRhodoscope FADC Hits
int Ndata_sbs_hodoPR_tdc_nhits;  //PRhodoscope TDC Hits
int Ndata_sbs_hodoPR_tdc_hits_t;   // PRhodoscope TDC all hits Time;time(ns)
int Ndata_sbs_hodoPR_tdc_hits_TDCelemID;  //PRhodoscope TDC all hits Element ID
 
double sbs_activeAna_adc_hits_a[10000];   //PRhodoscope FADC all Hits Pulse integral
double sbs_activeAna_adc_hits_a_amp[10000]; //PRhodoscope FADC all Hits Pulse amplitude
double sbs_activeAna_adc_hits_a_time[10000];  //PRhodoscope FADC all Hits Pulse Time
double sbs_activeAna_adc_adcelemID[10000]; //PRhodoscope FADC all good  Hits;Element ID 
double sbs_activeAna_adc_a_mult[10000];   //PRhodoscope FADC Multiplicity
double sbs_activeAna_adc_a_p[10000];   //PRhodoscope FADC Pulse Intergral 1D
double sbs_activeAna_adc_a_amp_p[10000];  //PRhodoscope FADC Amplitude 1D
double sbs_activeAna_adc_ped[10000];    //PRhodoscope FADC Pedestal 1D
double sbs_activeAna_adc_nhits[10000];   //PRhodoscope FADC Hits
double sbs_activeAna_tdc_nhits[10000];  //PRhodoscope TDC Hits
double sbs_activeAna_tdc_hits_t[10000];   // PRhodoscope TDC all hits Time;time(ns)
double sbs_activeAna_tdc_hits_TDCelemID[10000];  //PRhodoscope TDC all hits Element ID

int Ndata_sbs_activeAna_adc_hits_a;   //PRhodoscope FADC all Hits Pulse integral
int Ndata_sbs_activeAna_adc_hits_a_amp; //PRhodoscope FADC all Hits Pulse amplitude
int Ndata_sbs_activeAna_adc_hits_a_time;  //PRhodoscope FADC all Hits Pulse Time
int Ndata_sbs_activeAna_adc_adcelemID; //PRhodoscope FADC all good  Hits;Element ID 
int Ndata_sbs_activeAna_adc_a_mult;   //PRhodoscope FADC Multiplicity
int Ndata_sbs_activeAna_adc_a_p;   //PRhodoscope FADC Pulse Intergral 1D
int Ndata_sbs_activeAna_adc_a_amp_p;  //PRhodoscope FADC Amplitude 1D
int Ndata_sbs_activeAna_adc_ped;    //PRhodoscope FADC Pedestal 1D
int Ndata_sbs_activeAna_adc_nhits;   //PRhodoscope FADC Hits
int Ndata_sbs_activeAna_tdc_nhits;  //PRhodoscope TDC Hits
int Ndata_sbs_activeAna_tdc_hits_t;   // PRhodoscope TDC all hits Time;time(ns)
int Ndata_sbs_activeAna_tdc_hits_TDCelemID;  //PRhodoscope TDC all hits Element ID

T->SetBranchAddress("sbs.hodoPR_adc.hits.a", &sbs_hodoPR_adc_hits_a);
T->SetBranchAddress("sbs.hodoPR_adc.hits.a_amp", &sbs_hodoPR_adc_hits_a_amp);
T->SetBranchAddress("sbs.hodoPR_adc.hits.a_time", &sbs_hodoPR_adc_hits_a_time);
T->SetBranchAddress("sbs.hodoPR_adc.adcelemID", &sbs_hodoPR_adc_adcelemID);
T->SetBranchAddress("sbs.hodoPR_adc.a_p", &sbs_hodoPR_adc_a_p);
T->SetBranchAddress("sbs.hodoPR_adc.a_amp_p", &sbs_hodoPR_adc_a_amp_p);
T->SetBranchAddress("sbs.hodoPR_adc.ped", &sbs_hodoPR_adc_ped);
T->SetBranchAddress("sbs.hodoPR_adc.a_mult", &sbs_hodoPR_adc_a_mult);
T->SetBranchAddress("sbs.hodoPR_adc.nhits", &sbs_hodoPR_adc_nhits);
T->SetBranchAddress("sbs.hodoPR_tdc.nhits", &sbs_hodoPR_tdc_nhits);
T->SetBranchAddress("sbs.hodoPR_tdc.hits.t", &sbs_hodoPR_tdc_hits_t);
T->SetBranchAddress("sbs.hodoPR_tdc.hits.TDCelemID", &sbs_hodoPR_tdc_hits_TDCelemID);

T->SetBranchAddress("Ndata.sbs.hodoPR_adc.hits.a", &Ndata_sbs_hodoPR_adc_hits_a);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.hits.a_amp", &Ndata_sbs_hodoPR_adc_hits_a_amp);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.hits.a_time", &Ndata_sbs_hodoPR_adc_hits_a_time);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.adcelemID", &Ndata_sbs_hodoPR_adc_adcelemID);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.a_p", &Ndata_sbs_hodoPR_adc_a_p);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.a_amp_p", &Ndata_sbs_hodoPR_adc_a_amp_p);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.ped", &Ndata_sbs_hodoPR_adc_ped);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.a_mult", &Ndata_sbs_hodoPR_adc_a_mult);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.nhits", &Ndata_sbs_hodoPR_adc_nhits);
T->SetBranchAddress("Ndata.sbs.hodoPR_tdc.nhits", &Ndata_sbs_hodoPR_tdc_nhits);
T->SetBranchAddress("Ndata.sbs.hodoPR_tdc.hits.t", &Ndata_sbs_hodoPR_tdc_hits_t);
T->SetBranchAddress("Ndata.sbs.hodoPR_tdc.hits.TDCelemID", &Ndata_sbs_hodoPR_tdc_hits_TDCelemID);

T->SetBranchAddress("sbs.activeAna_adc.hits.a", &sbs_activeAna_adc_hits_a);
T->SetBranchAddress("sbs.activeAna_adc.hits.a_amp", &sbs_activeAna_adc_hits_a_amp);
T->SetBranchAddress("sbs.activeAna_adc.hits.a_time", &sbs_activeAna_adc_hits_a_time);
T->SetBranchAddress("sbs.activeAna_adc.adcelemID", &sbs_activeAna_adc_adcelemID);
T->SetBranchAddress("sbs.activeAna_adc.a_p", &sbs_activeAna_adc_a_p);
T->SetBranchAddress("sbs.activeAna_adc.a_amp_p", &sbs_activeAna_adc_a_amp_p);
T->SetBranchAddress("sbs.activeAna_adc.ped", &sbs_activeAna_adc_ped);
T->SetBranchAddress("sbs.activeAna_adc.a_mult", &sbs_activeAna_adc_a_mult);
T->SetBranchAddress("sbs.activeAna_adc.nhits", &sbs_activeAna_adc_nhits);
T->SetBranchAddress("sbs.activeAna_tdc.nhits", &sbs_activeAna_tdc_nhits);
T->SetBranchAddress("sbs.activeAna_tdc.hits.t", &sbs_activeAna_tdc_hits_t);
T->SetBranchAddress("sbs.activeAna_tdc.hits.TDCelemID", &sbs_activeAna_tdc_hits_TDCelemID);

T->SetBranchAddress("Ndata.sbs.activeAna_adc.hits.a", &Ndata_sbs_activeAna_adc_hits_a);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.hits.a_amp", &Ndata_sbs_activeAna_adc_hits_a_amp);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.hits.a_time", &Ndata_sbs_activeAna_adc_hits_a_time);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.adcelemID", &Ndata_sbs_activeAna_adc_adcelemID);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.a_p", &Ndata_sbs_activeAna_adc_a_p);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.a_amp_p", &Ndata_sbs_activeAna_adc_a_amp_p);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.ped", &Ndata_sbs_activeAna_adc_ped);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.a_mult", &Ndata_sbs_activeAna_adc_a_mult);
*/
T->SetBranchAddress("sbs.hodoPR_adc.a", &sbs_hodoPR_adc_a);
T->SetBranchAddress("sbs.hodoPR_adc.a_time", &sbs_hodoPR_adc_a_time);
T->SetBranchAddress("sbs.hodoPR_adc.adcelemID", &sbs_hodoPR_adc_adcelemID);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.a_time", &Ndata_sbs_hodoPR_adc_a_time);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.a", &Ndata_sbs_hodoPR_adc_a);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.adcelemID", &Ndata_sbs_hodoPR_adc_adcelemID);

T->SetBranchAddress("sbs.activeAna_adc.a", &sbs_activeAna_adc_a);
T->SetBranchAddress("sbs.activeAna_adc.a_time", &sbs_activeAna_adc_a_time);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.a_time", &Ndata_sbs_activeAna_adc_a_time);
T->SetBranchAddress("Ndata.sbs.activeAna_adc.a", &Ndata_sbs_activeAna_adc_a);

//FOr PR Layer1
T->SetBranchAddress("sbs.gemPR.m0.clust.clustu_time", &sbs_gemPR_m0_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m0.clust.clustv_time", &sbs_gemPR_m0_clust_clustv_time);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustu_time", &sbs_gemPR_m1_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustv_time", &sbs_gemPR_m1_clust_clustv_time);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustu_time", &sbs_gemPR_m2_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustv_time", &sbs_gemPR_m2_clust_clustv_time);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustu_time", &sbs_gemPR_m3_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustv_time", &sbs_gemPR_m3_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustu_time", &Ndata_sbs_gemPR_m0_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustv_time", &Ndata_sbs_gemPR_m0_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustu_time", &Ndata_sbs_gemPR_m1_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustv_time", &Ndata_sbs_gemPR_m1_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustu_time", &Ndata_sbs_gemPR_m2_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustv_time", &Ndata_sbs_gemPR_m2_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustu_time", &Ndata_sbs_gemPR_m3_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustv_time", &Ndata_sbs_gemPR_m3_clust_clustv_time);
//For PR Layer2
T->SetBranchAddress("sbs.gemPR.m4.clust.clustu_time", &sbs_gemPR_m4_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m4.clust.clustv_time", &sbs_gemPR_m4_clust_clustv_time);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustu_time", &sbs_gemPR_m5_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustv_time", &sbs_gemPR_m5_clust_clustv_time);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustu_time", &sbs_gemPR_m6_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustv_time", &sbs_gemPR_m6_clust_clustv_time);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustu_time", &sbs_gemPR_m7_clust_clustu_time);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustv_time", &sbs_gemPR_m7_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustu_time", &Ndata_sbs_gemPR_m4_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustv_time", &Ndata_sbs_gemPR_m4_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustu_time", &Ndata_sbs_gemPR_m5_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustv_time", &Ndata_sbs_gemPR_m5_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustu_time", &Ndata_sbs_gemPR_m6_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustv_time", &Ndata_sbs_gemPR_m6_clust_clustv_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustu_time", &Ndata_sbs_gemPR_m7_clust_clustu_time);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustv_time", &Ndata_sbs_gemPR_m7_clust_clustv_time);

T->SetBranchAddress("sbs.gemPR.m0.clust.clustu_adc", &sbs_gemPR_m0_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m0.clust.clustv_adc", &sbs_gemPR_m0_clust_clustv_adc);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustu_adc", &sbs_gemPR_m1_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustv_adc", &sbs_gemPR_m1_clust_clustv_adc);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustu_adc", &sbs_gemPR_m2_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustv_adc", &sbs_gemPR_m2_clust_clustv_adc);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustu_adc", &sbs_gemPR_m3_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustv_adc", &sbs_gemPR_m3_clust_clustv_adc);
T->SetBranchAddress("sbs.gemPR.m4.clust.clustu_adc", &sbs_gemPR_m4_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m4.clust.clustv_adc", &sbs_gemPR_m4_clust_clustv_adc);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustu_adc", &sbs_gemPR_m5_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustv_adc", &sbs_gemPR_m5_clust_clustv_adc);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustu_adc", &sbs_gemPR_m6_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustv_adc", &sbs_gemPR_m6_clust_clustv_adc);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustu_adc", &sbs_gemPR_m7_clust_clustu_adc);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustv_adc", &sbs_gemPR_m7_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustu_adc", &Ndata_sbs_gemPR_m0_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustv_adc", &Ndata_sbs_gemPR_m0_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustu_adc", &Ndata_sbs_gemPR_m1_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustv_adc", &Ndata_sbs_gemPR_m1_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustu_adc", &Ndata_sbs_gemPR_m2_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustv_adc", &Ndata_sbs_gemPR_m2_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustu_adc", &Ndata_sbs_gemPR_m3_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustv_adc", &Ndata_sbs_gemPR_m3_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustu_adc", &Ndata_sbs_gemPR_m4_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustv_adc", &Ndata_sbs_gemPR_m4_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustu_adc", &Ndata_sbs_gemPR_m5_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustv_adc", &Ndata_sbs_gemPR_m5_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustu_adc", &Ndata_sbs_gemPR_m6_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustv_adc", &Ndata_sbs_gemPR_m6_clust_clustv_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustu_adc", &Ndata_sbs_gemPR_m7_clust_clustu_adc);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustv_adc", &Ndata_sbs_gemPR_m7_clust_clustv_adc);

T->SetBranchAddress("sbs.gemPR.m0.clust.clustu_pos", &sbs_gemPR_m0_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m0.clust.clustv_pos", &sbs_gemPR_m0_clust_clustv_pos);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustu_pos", &sbs_gemPR_m1_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustv_pos", &sbs_gemPR_m1_clust_clustv_pos);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustu_pos", &sbs_gemPR_m2_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustv_pos", &sbs_gemPR_m2_clust_clustv_pos);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustu_pos", &sbs_gemPR_m3_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustv_pos", &sbs_gemPR_m3_clust_clustv_pos);
T->SetBranchAddress("sbs.gemPR.m4.clust.clustu_pos", &sbs_gemPR_m4_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m4.clust.clustv_pos", &sbs_gemPR_m4_clust_clustv_pos);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustu_pos", &sbs_gemPR_m5_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustv_pos", &sbs_gemPR_m5_clust_clustv_pos);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustu_pos", &sbs_gemPR_m6_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustv_pos", &sbs_gemPR_m6_clust_clustv_pos);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustu_pos", &sbs_gemPR_m7_clust_clustu_pos);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustv_pos", &sbs_gemPR_m7_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustu_pos", &Ndata_sbs_gemPR_m0_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustv_pos", &Ndata_sbs_gemPR_m0_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustu_pos", &Ndata_sbs_gemPR_m1_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustv_pos", &Ndata_sbs_gemPR_m1_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustu_pos", &Ndata_sbs_gemPR_m2_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustv_pos", &Ndata_sbs_gemPR_m2_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustu_pos", &Ndata_sbs_gemPR_m3_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustv_pos", &Ndata_sbs_gemPR_m3_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustu_pos", &Ndata_sbs_gemPR_m4_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustv_pos", &Ndata_sbs_gemPR_m4_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustu_pos", &Ndata_sbs_gemPR_m5_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustv_pos", &Ndata_sbs_gemPR_m5_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustu_pos", &Ndata_sbs_gemPR_m6_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustv_pos", &Ndata_sbs_gemPR_m6_clust_clustv_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustu_pos", &Ndata_sbs_gemPR_m7_clust_clustu_pos);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustv_pos", &Ndata_sbs_gemPR_m7_clust_clustv_pos);

/*
T->SetBranchAddress("Ndata.sbs.activeAna_adc.nhits", &Ndata_sbs_activeAna_adc_nhits);
T->SetBranchAddress("Ndata.sbs.activeAna_tdc.nhits", &Ndata_sbs_activeAna_tdc_nhits);
T->SetBranchAddress("Ndata.sbs.activeAna_tdc.hits.t", &Ndata_sbs_activeAna_tdc_hits_t);
T->SetBranchAddress("Ndata.sbs.activeAna_tdc.hits.TDCelemID", &Ndata_sbs_activeAna_tdc_hits_TDCelemID);

TH1F *PRHodo_fadc_hits_int  = new TH1F("PRHodo_fadc_hits_int", "PRhodo FADC All Hits Pulse Integral",50, 0.1, 300);
TH1F *PRHodo_fadc_hits_amp  =new TH1F("PRHodo_fadc_hits_amp", "PRhodo FADC All Hits Pulse Amplitude",50, 0.1, 400);
TH1F *PRHodo_fadc_hits_time =new TH1F("PRHodo_fadc_hits_time" ,"PRhodo FADC All Hits Pulse Time",100, 0.1, 1600);
TH1F *PRHodo_fadc_elemID    =new TH1F("PRHodo_fadc_elemID" , "PRHodo FADC good Hits",48, -0.5, 47.5);
TH1F *PRHodo_h1_int  = new TH1F("PRHodo_h1_int", "PRHodo FADC Pulse Integral", 50, 0.1, 300);
TH1F *PRHodo_h1_amp  = new TH1F("PRHodo_h1_amp", "PRHodo FADC Amplitude 1D", 50, 0.1, 400);
TH1F *PRHodo_h1_ped  = new TH1F("PRHodo_h1_ped", "PRHo FADC Pedestal",25,0.1, 50);
TH1F *PRHodo_h1_mult  = new TH1F("PRHodo_h1_mult", "PRHodo FADC multiplicity 1D", 50, -0.5, 4.5);
TH1F *PRHodo_fadc_nhits = new TH1F("PRHodo_fadc_nhits", "PRHodo FADC Hits", 50, 0.5,50.5);
TH1F *PRHodo_tdc_nhits = new TH1F("PRHodo_tdc_nhits", "PRHodo TDC Hits", 50, 0.5,50.5);
TH1F *PRHodo_tdc_hits_time = new TH1F("PRHodo_tdc_hits_time", "PRHodo TDC All Hits Time",100, 0.1,13000);
TH1F *PRHodo_tdc_elemid = new TH1F("PRHodo_tdc_elemid", "PRHodo TDC All Hits; Elememt ID",48, -0.5,47.5);

TH1F *activeAna_fadc_hits_int  = new TH1F("activeAna_fadc_hits_int", "activeAna FADC All Hits Pulse Integral",50, 0.1, 300);
TH1F *activeAna_fadc_hits_amp  =new TH1F("activeAna_fadc_hits_amp", "activeAna FADC All Hits Pulse Amplitude",50, 0.1, 400);
TH1F *activeAna_fadc_hits_time =new TH1F("activeAna_fadc_hits_time", "activeAna FADC All Hits Pulse Time",100, 0.1, 1600);
TH1F *activeAna_fadc_elemID    =new TH1F("activeAna_fadc_elemID", "activeAna FADC good Hits",32, -0.5, 31.5);
TH1F *activeAna_h1_int  = new TH1F("activeAna_h1_int", "activeAna FADC Pulse Integral", 50, 0.1, 300);
TH1F *activeAna_h1_amp  = new TH1F("activeAna_h1_amp", "activeAna FADC Amplitude 1D", 50, 0.1, 400);
TH1F *activeAna_h1_ped  = new TH1F("activeAna_h1_ped ", "activeAna FADC Pedestal",25,0.1, 50);
TH1F *activeAna_h1_mult  = new TH1F("activeAna_h1_mult", "activeAna FADC multiplicity 1D", 50, -0.5, 4.5);
TH1F *activeAna_fadc_nhits = new TH1F("activeAna_fadc_nhits", "activeAna FADC Hits", 50, 0.1,50);
TH1F *activeAna_tdc_nhits = new TH1F("activeAna_tdc_nhits", "activeAna TDC Hits", 50, 0.1,50);
TH1F *activeAna_tdc_hits_time = new TH1F("activeAna_tdc_hits_time", "activeAna TDC All Hits Time", 100, 0.1,13000);
TH1F *activeAna_tdc_elemid = new TH1F("activeAna_tdc_elemid", "activeAna TDC All Hits; Elememt ID",32, -0.5,31.5);

//2D hodoPR FADC histograms
//#-----------------------------------------------------------------------------
TH2F *hodoPR_fadc_int_id  =new TH2F("hodoPR_fadc_int_id","PR Hodo FADC Pulse Integral", 50, -0.5, 49.5, 50, 0.1, 300);
TH2F *hodoPR_fadc_amp_id  = new TH2F("hodoPR_fadc_amp_id","PR Hodo FADC Amplitude", 50, -0.5, 49.5, 50, 0.1, 400);
TH2F *hodoPR_fadc_ped_id  = new  TH2F("hodoPR_fadc_ped_id","PR Hodo Pedestal",  50, -0.5, 49.5, 25, -0.5, 50.5);
TH2F *hodoPR_fadc_mult_id = new TH2F("hodoPR_fadc_mult_id","PR Hodo FADC Multiplicity", 50, -0.5, 49.5, 5, -0.5, 4.5);

TH2F *activeAna_fadc_int_id  =new TH2F("activeAna_fadc_int_id","ActiveAna FADC Pulse Integral", 40, -0.5, 39.5, 50, 0.1, 300);
TH2F *activeAna_fadc_amp_id  = new TH2F("activeAna_fadc_amp_id","ActiveAna FADC Amplitude", 40,-0.5, 39.5, 50, 0.1, 400);
TH2F *activeAna_fadc_ped_id  = new  TH2F("activeAna_fadc_ped_id","ActiveAna FADC Pedestal", 40,-0.5, 39.5, 25, -0.5, 50.5);
TH2F *activeAna_fadc_mult_id = new TH2F("activeAna_fadc_mult_id","ActiveAna FADC Multiplicity", 40, -0.5, 39.5, 5, -0.5, 4.5);
*/

//2D Histogram plots for timing information od HodoPR_adc_time vs PRgems_clust_time
//making 2D histogram for PR GEMS
TH2F *h_m0m4_U = new TH2F("h_m0m4_U","ClustU_time_m0 vs ClustU_time_m4",100,-2,150, 100,0,140 );
TH2F *h_m1m5_U = new TH2F("h_m1m5_U","ClustU_time_m1 vs  ClustU_time_m5",100,-2,150,100,0,140);
TH2F *h_m2m6_U = new TH2F("h_m2m6_U","ClustU_time_m2 vs  ClustU_time_m6",100,-2,150,100,0,140);
TH2F *h_m3m7_U = new TH2F("h_m3m7_U","ClustU_time_m3 vs  ClustU_time_m7",100,-2,150,100,0,140);
TH2F *h_m0m4_V = new TH2F("h_m0m4_V","ClustV_time_m0 vs  ClustV_time_m4",100,-2,150,100,0,140);
TH2F *h_m1m5_V = new TH2F("h_m1m5_V","ClustV_time_m1 vs  ClustV_time_m5",100,-2,150,100,0,140);
TH2F *h_m2m6_V = new TH2F("h_m2m6_V","ClustV_time_m2 vs  ClustV_time_m6",100,-2,150,100,0,140);
TH2F *h_m3m7_V = new TH2F("h_m3m7_V","ClustV_time_m3 vs  ClustV_time_m7",100,-2,150,100,0,140);

TH2F *h_m0m4_Um = new TH2F("h_m0m4_Um","ClustU_pos_m0 vs  ClustU_pos_m4",100,-0.1,0.4,100,-0.1,0.4);
TH2F *h_m1m5_Um = new TH2F("h_m1m5_Um","ClustU_pos_m1 vs  ClustU_pos_m5",100,-0.1,0.4,100,-0.1,0.4);
TH2F *h_m2m6_Um = new TH2F("h_m2m6_Um","ClustU_pos_m2 vs  ClustU_pos_m6",100,-0.1,0.4,100,-0.1,0.4);
TH2F *h_m3m7_Um = new TH2F("h_m3m7_Um","ClustU_pos_m3 vs  ClustU_pos_m7",100,-0.1,0.4,100,-0.1,0.4);
TH2F *h_m0m4_Vm = new TH2F("h_m0m4_Vm","ClustV_pos_m0 vs  ClustV_pos_m4",100,-0.1,0.4,100,-0.1,0.4);
TH2F *h_m1m5_Vm = new TH2F("h_m1m5_Vm","ClustV_pos_m1 vs  ClustV_pos_m5",100,-0.1,0.4,100,-0.1,0.4);
TH2F *h_m2m6_Vm = new TH2F("h_m2m6_Vm","ClustV_pos_m2 vs  ClustV_pos_m6",100,-0.1,0.4,100,-0.1,0.4);
TH2F *h_m3m7_Vm = new TH2F("h_m3m7_Vm","ClustV_pos_m3 vs  ClustV_pos_m7",100,-0.1,0.4,100,-0.1,0.4);

TH1F *h_m0_m4_U = new TH1F("h_m0_m4_U","ClustU_time_m0-m4",140,-140,140 );
TH1F *h_m1_m5_U = new TH1F("h_m1_m5_U","ClustU_time_m1-m5",140,-140,140);
TH1F *h_m2_m6_U = new TH1F("h_m2_m6_U","ClustU_time_m2-m6",140,-140,140);
TH1F *h_m3_m7_U = new TH1F("h_m3_m7_U","ClustU_time_m3-m7",140,-140,140);
TH1F *h_m0_m4_V = new TH1F("h_m0_m4_V","ClustV_time_m0-m4",140,-140,140);
TH1F *h_m1_m5_V = new TH1F("h_m1_m5_V","ClustV_time_m1-m5",140,-140,140);
TH1F *h_m2_m6_V = new TH1F("h_m2_m6_V","ClustV_time_m2-m6",140,-140,140);
TH1F *h_m3_m7_V = new TH1F("h_m3_m7_V","ClustV_time_m3-m7",140,-140,140);

TH1F *h_m0_m4_Um = new TH1F("h_m0_m4_Um","ClustU_pos_m0-m4",140,-0.3,0.3);
TH1F *h_m1_m5_Um = new TH1F("h_m1_m5_Um","ClustU_pos_m1-m5",140,-0.3,0.3);
TH1F *h_m2_m6_Um = new TH1F("h_m2_m6_Um","ClustU_pos_m2-m6",140,-0.3,0.3);
TH1F *h_m3_m7_Um = new TH1F("h_m3_m7_Um","ClustU_pos_m3-m7",140,-0.3,0.3);
TH1F *h_m0_m4_Vm = new TH1F("h_m0_m4_Vm","ClustV_pos_m0-m4",140,-0.3,0.3);
TH1F *h_m1_m5_Vm = new TH1F("h_m1_m5_Vm","ClustV_pos_m1-m5",140,-0.3,0.3);
TH1F *h_m2_m6_Vm = new TH1F("h_m2_m6_Vm","ClustV_pos_m2-m6",140,-0.3,0.3);
TH1F *h_m3_m7_Vm = new TH1F("h_m3_m7_Vm","ClustV_pos_m3-m7",140,-0.3,0.3);


TH2F *h_m0_UV = new TH2F("h_m0_UV","ClustU_time_m0 vs ClustV_time_m0",100,-2,150, 100,0,140 );
TH2F *h_m1_UV = new TH2F("h_m1_UV","ClustU_time_m1 vs  ClustV_time_m1",100,-2,150,100,0,140);
TH2F *h_m2_UV = new TH2F("h_m2_UV","ClustU_time_m2 vs  ClustV_time_m2",100,-2,150,100,0,140);
TH2F *h_m3_UV = new TH2F("h_m3_UV","ClustU_time_m3 vs  ClustV_time_m3",100,-2,150,100,0,140);
TH2F *h_m4_UV = new TH2F("h_m4_UV","ClustU_time_m4 vs  ClustV_time_m4",100,-2,150,100,0,140);
TH2F *h_m5_UV = new TH2F("h_m5_UV","ClustU_time_m5 vs  ClustV_time_m5",100,-2,150,100,0,140);
TH2F *h_m6_UV = new TH2F("h_m6_UV","ClustU_time_m6 vs  ClustV_time_m6",100,-2,150,100,0,140);
TH2F *h_m7_UV = new TH2F("h_m7_UV","ClustU_time_m7 vs  ClustV_time_m7",100,-2,150,100,0,140);

TH2F *h_m0_UVm = new TH2F("h_m0_UVm","ClustU_pos_m0 vs  ClustV_pos_m0",100,-0.4,0.4,100,-0.4,0.4);
TH2F *h_m1_UVm = new TH2F("h_m1_UVm","ClustU_pos_m1 vs  ClustV_pos_m1",100,-0.4,0.4,100,-0.4,0.4);
TH2F *h_m2_UVm = new TH2F("h_m2_UVm","ClustU_pos_m2 vs  ClustV_pos_m2",100,-0.4,0.4,100,-0.4,0.4);
TH2F *h_m3_UVm = new TH2F("h_m3_UVm","ClustU_pos_m3 vs  ClustV_pos_m3",100,-0.4,0.4,100,-0.4,0.4);
TH2F *h_m4_UVm = new TH2F("h_m4_UVm","ClustU_pos_m4 vs  ClustV_pos_m4",100,-0.4,0.4,100,-0.4,0.4);
TH2F *h_m5_UVm = new TH2F("h_m5_UVm","ClustU_pos_m5 vs  ClustV_pos_m5",100,-0.4,0.4,100,-0.4,0.4);
TH2F *h_m6_UVm = new TH2F("h_m6_UVm","ClustU_pos_m6 vs  ClustV_pos_m6",100,-0.4,0.4,100,-0.4,0.4);
TH2F *h_m7_UVm = new TH2F("h_m7_UVm","ClustU_pos_m7 vs  ClustV_pos_m7",100,-0.4,0.4,100,-0.4,0.4);


TH1F *h_m0_U_V = new TH1F("h_m0_U_V","ClustU_time - ClustV_time_m0",140,-140,140);
TH1F *h_m1_U_V = new TH1F("h_m1_U_V","ClustU_time - ClustV_time_m1",140,-140,140);
TH1F *h_m2_U_V = new TH1F("h_m2_U_V","ClustU_time - ClustV_time_m2",140,-140,140);
TH1F *h_m3_U_V = new TH1F("h_m3_U_V","ClustU_time - ClustV_time_m3",140,-140,140);
TH1F *h_m4_U_V = new TH1F("h_m4_U_V","ClustU_time - ClustV_time_m4",140,-140,140);
TH1F *h_m5_U_V = new TH1F("h_m5_U_V","ClustU_time - ClustV_time_m5",140,-140,140);
TH1F *h_m6_U_V = new TH1F("h_m6_U_V","ClustU_time - ClustV_time_m6",140,-140,140);
TH1F *h_m7_U_V = new TH1F("h_m7_U_V","ClustU_time - ClustV_time_m7",140,-140,140);

TH1F *h_m0_Um_Vm = new TH1F("h_m0_Um_Vm","ClustU_pos - ClustV_pos_m0",140,-0.3,0.3);
TH1F *h_m1_Um_Vm = new TH1F("h_m1_Um_Vm","ClustU_pos - ClustV_pos_m1",140,-0.3,0.3);
TH1F *h_m2_Um_Vm = new TH1F("h_m2_Um_Vm","ClustU_pos - ClustV_pos_m2",140,-0.3,0.3);
TH1F *h_m3_Um_Vm = new TH1F("h_m3_Um_Vm","ClustU_pos - ClustV_pos_m3",140,-0.3,0.3);
TH1F *h_m4_Um_Vm = new TH1F("h_m4_Um_Vm","ClustU_pos - ClustV_pos_m4",140,-0.3,0.3);
TH1F *h_m5_Um_Vm = new TH1F("h_m5_Um_Vm","ClustU_pos - ClustV_pos_m5",140,-0.3,0.3);
TH1F *h_m6_Um_Vm = new TH1F("h_m6_Um_Vm","ClustU_pos - ClustV_pos_m6",140,-0.3,0.3);
TH1F *h_m7_Um_Vm = new TH1F("h_m7_Um_Vm","ClustU_pos - ClustV_pos_m7",140,-0.3,0.3);


//making 2D histogram for PR GEMS
TH2F *hPRhodoVsPRGEMHits_m0m4_U = new TH2F("hPRhodoVsPRGEMHits_m0m4_U","HodoPR_adc_time vs ClustU_time_m0m4",300,-5,550,150,0,150);
TH2F *hPRhodoVsPRGEMHits_m1m5_U= new TH2F("hPRhodoVsPRGEMHits_m1m5_U","HodoPR_adc_time vs  ClustU_time_m1m5",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m2m6_U= new TH2F("hPRhodoVsPRGEMHits_m2m6_U","HodoPR_adc_time vs  ClustU_time_m2m6",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m3m7_U= new TH2F("hPRhodoVsPRGEMHits_m3m7_U","HodoPR_adc_time vs  ClustU_time_m3m7",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m0m4_V = new TH2F("hPRhodoVsPRGEMHits_m0m4_V","HodoPR_adc_time vs ClustV_time_m0m4",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m1m5_V= new TH2F("hPRhodoVsPRGEMHits_m1m5_V","HodoPR_adc_time vs  ClustV_time_m1m5",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m2m6_V= new TH2F("hPRhodoVsPRGEMHits_m2m6_V","HodoPR_adc_time vs  ClustV_time_m2m6",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m3m7_V= new TH2F("hPRhodoVsPRGEMHits_m3m7_V","HodoPR_adc_time vs  ClustV_time_m3m7",300,-50,550,12,-12,12);

//making 2D histogram for PR GEMS
TH2F *hPRhodoVsPRGEMHits_m0m4_Um = new TH2F("hPRhodoVsPRGEMHits_m0m4_Um","HodoPR_adc_time vs ClustU_pos_m0m4",300,-50,550,140,-0.4,0.4);
TH2F *hPRhodoVsPRGEMHits_m1m5_Um= new TH2F("hPRhodoVsPRGEMHits_m1m5_Um","HodoPR_adc_time vs  ClustU_pos_m1m5",300,-50,550,140,-0.4,0.4);
TH2F *hPRhodoVsPRGEMHits_m2m6_Um= new TH2F("hPRhodoVsPRGEMHits_m2m6_Um","HodoPR_adc_time vs  ClustU_pos_m2m6",300,-50,550,140,-0.4,0.4);
TH2F *hPRhodoVsPRGEMHits_m3m7_Um= new TH2F("hPRhodoVsPRGEMHits_m3m7_Um","HodoPR_adc_time vs  ClustU_pos_m3m7",300,-50,550,140,-0.4,0.4);
TH2F *hPRhodoVsPRGEMHits_m0m4_Vm = new TH2F("hPRhodoVsPRGEMHits_m0m4_Vm","HodoPR_adc_time vs ClustV_pos_m0m4",300,-50,550,140,-0.4,0.4);
TH2F *hPRhodoVsPRGEMHits_m1m5_Vm= new TH2F("hPRhodoVsPRGEMHits_m1m5_Vm","HodoPR_adc_time vs  ClustV_pos_m1m5",300,-50,550,140,-0.4,0.4);
TH2F *hPRhodoVsPRGEMHits_m2m6_Vm= new TH2F("hPRhodoVsPRGEMHits_m2m6_Vm","HodoPR_adc_time vs  ClustV_pos_m2m6",300,-50,550,140,-0.4,0.4);
TH2F *hPRhodoVsPRGEMHits_m3m7_Vm= new TH2F("hPRhodoVsPRGEMHits_m3m7_Vm","HodoPR_adc_time vs  ClustV_pos_m3m7",300,-50,550,140,-0.4,0.4);

//2D plots with respect to hodoPR_adc_elemID
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U = new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U","HodoPR_adc_adcelemID vs ClustU_time_m0m4",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U","HodoPR_adc_adcelemID vs  ClustU_time_m1m5",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U","HodoPR_adc_adcelemID vs ClustU_time_m2m6", 30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U","HodoPR_adc_adcelemID vs  ClustU_time_m3m7",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V = new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V","HodoPR_adc_adcelemID vs ClustV_time_m0m4",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V","HodoPR_adc_adcelemID  vs ClustV_time_m1m5", 30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V","HodoPR_adc_adcelemID vs  ClustV_time_m2m6",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V","HodoPR_adc_adcelemID vs  ClustV_time_m3m7",30,-5,55,12,-12,12);


//making 2D histogram for PR GEMS with Active_Analyzer
TH2F *hactiveAnaVsPRGEMHits_m0m4_U = new TH2F("hactiveAnaVsPRGEMHits_m0m4_U","activeAna_adc_time vs ClustU_time_m0m4",300,-50,550,12,-12,12);
TH2F *hactiveAnaVsPRGEMHits_m1m5_U= new TH2F("hactiveAnaVsPRGEMHits_m1m5_U","activeAna_adc_time vs  ClustU_time_m1m5",300,-50,550,12,-12,12);
TH2F *hactiveAnaVsPRGEMHits_m2m6_U= new TH2F("hactiveAnaVsPRGEMHits_m2m6_U","activeAna_adc_time vs  ClustU_time_m2m6",300,-50,550,12,-12,12);
TH2F *hactiveAnaVsPRGEMHits_m3m7_U= new TH2F("hactiveAnaVsPRGEMHits_m3m7_U","activeAna_adc_time vs  ClustU_time_m3m7",300,-50,550,12,-12,12);
TH2F *hactiveAnaVsPRGEMHits_m0m4_V= new TH2F("hactiveAnaVsPRGEMHits_m0m4_V","activeAna_adc_time vs ClustU_time_m0m4",300,-50, 550,12,-12,12);
TH2F *hactiveAnaVsPRGEMHits_m1m5_V= new TH2F("hactiveAnaVsPRGEMHits_m1m5_V","activeAna_adc_time vs  ClustU_time_m1m5",300,-50,550,12,-12,12);
TH2F *hactiveAnaVsPRGEMHits_m2m6_V= new TH2F("hactiveAnaVsPRGEMHits_m2m6_V","activeAna_adc_time vs  ClustU_time_m2m6",300,-50,550,12,-12,12);
TH2F *hactiveAnaVsPRGEMHits_m3m7_V= new TH2F("hactiveAnaVsPRGEMHits_m3m7_V","activeAna_adc_time vs  ClustU_time_m3m7",300,-50,550,12,-12,12);



Long64_t nentries = T->GetEntries();
for (Long64_t i = 0; i<nentries ; i++) {
   T->GetEntry(i);  

//cout<<"value" <<i<<'\t' << Ndata_sbs_gemPR_m0_clust_clustu_adc<<'\t'<< Ndata_sbs_gemPR_m0_clust_clustu_time<<endl;
// Fill histogram for X1 vs Y1
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_adc; j++){
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_adc; n++){
    double Time_Diffrence_m0m4_U =sbs_gemPR_m0_clust_clustu_time[j] - sbs_gemPR_m4_clust_clustu_time[n];
     h_m0m4_U->Fill(sbs_gemPR_m0_clust_clustu_time[j],sbs_gemPR_m4_clust_clustu_time[n]);
     h_m0_m4_U->Fill(Time_Diffrence_m0m4_U);
}}  
for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
   double Time_Diffrence_m1m5_U =sbs_gemPR_m1_clust_clustu_time[k] - sbs_gemPR_m5_clust_clustu_time[o];
    h_m1m5_U->Fill(sbs_gemPR_m1_clust_clustu_time[k],sbs_gemPR_m5_clust_clustu_time[o]);
    h_m1_m5_U->Fill(Time_Diffrence_m1m5_U);
}}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
   double Time_Diffrence_m2m6_U =sbs_gemPR_m2_clust_clustu_time[l] - sbs_gemPR_m6_clust_clustu_time[p];
  h_m2m6_U->Fill(sbs_gemPR_m2_clust_clustu_time[l],sbs_gemPR_m6_clust_clustu_time[p]);
  h_m2_m6_U->Fill(Time_Diffrence_m2m6_U);
}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
    double Time_Diffrence_m3m7_U =sbs_gemPR_m3_clust_clustu_time[m] - sbs_gemPR_m7_clust_clustu_time[q];
   h_m3m7_U->Fill(sbs_gemPR_m3_clust_clustu_time[m],sbs_gemPR_m7_clust_clustu_time[q]);
   h_m3_m7_U->Fill(Time_Diffrence_m3m7_U);
}}
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
   double Time_Diffrence_m0m4_V =sbs_gemPR_m0_clust_clustv_time[j1] - sbs_gemPR_m4_clust_clustv_time[n1];
   h_m0m4_V->Fill(sbs_gemPR_m0_clust_clustv_time[j1],sbs_gemPR_m4_clust_clustv_time[n1]);
   h_m0_m4_V->Fill(Time_Diffrence_m0m4_V);   
}}
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
    double Time_Diffrence_m1m5_V =sbs_gemPR_m1_clust_clustv_time[k1] - sbs_gemPR_m5_clust_clustv_time[o1];
    h_m1m5_V->Fill(sbs_gemPR_m1_clust_clustv_time[k1],sbs_gemPR_m5_clust_clustv_time[o1]);
    h_m1_m5_V->Fill(Time_Diffrence_m1m5_V);  
  }}
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
   double Time_Diffrence_m2m6_V =sbs_gemPR_m2_clust_clustv_time[l1] - sbs_gemPR_m6_clust_clustv_time[p1];
    h_m2m6_V->Fill(sbs_gemPR_m2_clust_clustv_time[l1],sbs_gemPR_m6_clust_clustv_time[p1]);
   h_m2_m6_V->Fill(Time_Diffrence_m2m6_V);   
}}
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
    double Time_Diffrence_m3m7_V =sbs_gemPR_m3_clust_clustv_time[m1] - sbs_gemPR_m7_clust_clustv_time[q1];
    h_m3m7_V->Fill(sbs_gemPR_m3_clust_clustv_time[m1],sbs_gemPR_m7_clust_clustv_time[q1]);
    h_m3_m7_V->Fill(Time_Diffrence_m3m7_V);
}}
// for Position
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_adc; j++){
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_adc; n++){
for (int j1=0; j1< Ndata_sbs_hodoPR_adc_a; j1++){
if (sbs_gemPR_m0_clust_clustu_pos[j]>0 && sbs_gemPR_m4_clust_clustu_pos[n]>0 && sbs_hodoPR_adc_a_time[j1]>0) {
    double pos_Diffrence_m0m4_Um =sbs_gemPR_m0_clust_clustu_pos[j] - sbs_gemPR_m4_clust_clustu_pos[n];
     hPRhodoVsPRGEMHits_m0m4_Um->Fill( sbs_hodoPR_adc_a_time[j1],pos_Diffrence_m0m4_Um);
     h_m0m4_Um->Fill(sbs_gemPR_m0_clust_clustu_pos[j],sbs_gemPR_m4_clust_clustu_pos[n]);
     h_m0_m4_Um->Fill(pos_Diffrence_m0m4_Um);
}}}}
for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
for (int k1=0; k1< Ndata_sbs_hodoPR_adc_a; k1++){
if (sbs_gemPR_m1_clust_clustu_pos[k]>0 && sbs_gemPR_m5_clust_clustu_pos[o]>0 && sbs_hodoPR_adc_a_time[k1]>0) {
   double pos_Diffrence_m1m5_Um =sbs_gemPR_m1_clust_clustu_pos[k] - sbs_gemPR_m5_clust_clustu_pos[o];
    hPRhodoVsPRGEMHits_m1m5_Um->Fill( sbs_hodoPR_adc_a_time[k1],pos_Diffrence_m1m5_Um);
    h_m1m5_Um->Fill(sbs_gemPR_m1_clust_clustu_pos[k],sbs_gemPR_m5_clust_clustu_pos[o]);
    h_m1_m5_Um->Fill(pos_Diffrence_m1m5_Um);
}}}}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
for (int l1=0; l1< Ndata_sbs_hodoPR_adc_a; l1++){
if (sbs_gemPR_m2_clust_clustu_pos[l]>0 && sbs_gemPR_m6_clust_clustu_pos[p]>0 && sbs_hodoPR_adc_a_time[l1]>0) {
   double pos_Diffrence_m2m6_Um =sbs_gemPR_m2_clust_clustu_pos[l] - sbs_gemPR_m6_clust_clustu_pos[p];
  hPRhodoVsPRGEMHits_m2m6_Um->Fill( sbs_hodoPR_adc_a_time[l1],pos_Diffrence_m2m6_Um);
  h_m2m6_Um->Fill(sbs_gemPR_m2_clust_clustu_pos[l],sbs_gemPR_m6_clust_clustu_pos[p]);
  h_m2_m6_Um->Fill(pos_Diffrence_m2m6_Um);
}}}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
for (int m1=0; m1< Ndata_sbs_hodoPR_adc_a; m1++){
if (sbs_gemPR_m3_clust_clustu_pos[m]>0 && sbs_gemPR_m7_clust_clustu_pos[q]>0 && sbs_hodoPR_adc_a_time[m1]>0) {
    double pos_Diffrence_m3m7_Um =sbs_gemPR_m3_clust_clustu_pos[m] - sbs_gemPR_m7_clust_clustu_pos[q];
   hPRhodoVsPRGEMHits_m3m7_Um->Fill( sbs_hodoPR_adc_a_time[m1],pos_Diffrence_m3m7_Um);
   h_m3m7_Um->Fill(sbs_gemPR_m3_clust_clustu_pos[m],sbs_gemPR_m7_clust_clustu_pos[q]);
   h_m3_m7_Um->Fill(pos_Diffrence_m3m7_Um);
}}}}
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
for (int j2=0; j2< Ndata_sbs_hodoPR_adc_a; j2++){
if (sbs_gemPR_m0_clust_clustv_pos[j1]>0 && sbs_gemPR_m4_clust_clustv_pos[n1]>0 && sbs_hodoPR_adc_a_time[j2]>0) {
   double pos_Diffrence_m0m4_Vm =sbs_gemPR_m0_clust_clustv_pos[j1] - sbs_gemPR_m4_clust_clustv_pos[n1];
   hPRhodoVsPRGEMHits_m0m4_Vm->Fill( sbs_hodoPR_adc_a_time[j2],pos_Diffrence_m0m4_Vm);
   h_m0m4_Vm->Fill(sbs_gemPR_m0_clust_clustv_pos[j1],sbs_gemPR_m4_clust_clustv_pos[n1]);
   h_m0_m4_Vm->Fill(pos_Diffrence_m0m4_Vm);
}}}}
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
for (int k2=0; k2< Ndata_sbs_hodoPR_adc_a; k2++){
if (sbs_gemPR_m1_clust_clustv_pos[k1]>0 && sbs_gemPR_m5_clust_clustv_pos[o1]>0 && sbs_hodoPR_adc_a_time[k2]>0) {
    double pos_Diffrence_m1m5_Vm =sbs_gemPR_m1_clust_clustv_pos[k1] - sbs_gemPR_m5_clust_clustv_pos[o1];
    hPRhodoVsPRGEMHits_m1m5_Vm->Fill( sbs_hodoPR_adc_a_time[k2],pos_Diffrence_m1m5_Vm);
    h_m1m5_Vm->Fill(sbs_gemPR_m1_clust_clustv_pos[k1],sbs_gemPR_m5_clust_clustv_pos[o1]);
    h_m1_m5_Vm->Fill(pos_Diffrence_m1m5_Vm);
  }}}}
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
for (int l2=0; l2< Ndata_sbs_hodoPR_adc_a; l2++){
if (sbs_gemPR_m2_clust_clustv_pos[l1]>0 && sbs_gemPR_m6_clust_clustv_pos[p1]>0 && sbs_hodoPR_adc_a_time[l2]>0) {
   double pos_Diffrence_m2m6_Vm =sbs_gemPR_m2_clust_clustv_pos[l1] - sbs_gemPR_m6_clust_clustv_pos[p1];
    hPRhodoVsPRGEMHits_m2m6_Vm->Fill( sbs_hodoPR_adc_a_time[l2],pos_Diffrence_m2m6_Vm);
    h_m2m6_Vm->Fill(sbs_gemPR_m2_clust_clustv_pos[l1],sbs_gemPR_m6_clust_clustv_pos[p1]);
   h_m2_m6_Vm->Fill(pos_Diffrence_m2m6_Vm);
}}}}
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
for (int m2=0; m2< Ndata_sbs_hodoPR_adc_a; m2++){
if (sbs_gemPR_m3_clust_clustv_pos[m1]>0 && sbs_gemPR_m7_clust_clustv_pos[q1]>0 && sbs_hodoPR_adc_a_time[m2]>0) {
    double pos_Diffrence_m3m7_Vm =sbs_gemPR_m3_clust_clustv_pos[m1] - sbs_gemPR_m7_clust_clustv_pos[q1];
    hPRhodoVsPRGEMHits_m3m7_Vm->Fill( sbs_hodoPR_adc_a_time[m2],pos_Diffrence_m3m7_Vm);
    h_m3m7_Vm->Fill(sbs_gemPR_m3_clust_clustv_pos[m1],sbs_gemPR_m7_clust_clustv_pos[q1]);
    h_m3_m7_Vm->Fill(pos_Diffrence_m3m7_Vm);
}}}}

//UV per module
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_adc; j++){
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
  double Time_Diffrence_m0_U_V =sbs_gemPR_m0_clust_clustu_time[j] - sbs_gemPR_m0_clust_clustv_time[j1];
h_m0_UV->Fill(sbs_gemPR_m0_clust_clustu_time[j],sbs_gemPR_m0_clust_clustv_time[j1]);
h_m0_U_V->Fill(Time_Diffrence_m0_U_V);
}}
for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
  double Time_Diffrence_m1_U_V =sbs_gemPR_m1_clust_clustu_time[k] - sbs_gemPR_m1_clust_clustv_time[k1];
h_m1_UV->Fill(sbs_gemPR_m1_clust_clustu_time[k],sbs_gemPR_m1_clust_clustv_time[k1]);
h_m1_U_V->Fill(Time_Diffrence_m1_U_V);
 }}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
double Time_Diffrence_m2_U_V =sbs_gemPR_m2_clust_clustu_time[l] - sbs_gemPR_m2_clust_clustv_time[l1];
h_m2_UV->Fill(sbs_gemPR_m2_clust_clustu_time[l],sbs_gemPR_m2_clust_clustv_time[l1]);
h_m2_U_V->Fill(Time_Diffrence_m2_U_V);
}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
double Time_Diffrence_m3_U_V =sbs_gemPR_m3_clust_clustu_time[m] - sbs_gemPR_m3_clust_clustv_time[m1];
h_m3_UV->Fill(sbs_gemPR_m3_clust_clustu_time[m],sbs_gemPR_m3_clust_clustv_time[m1]);
h_m3_U_V->Fill(Time_Diffrence_m3_U_V);
}}
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_adc; n++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
double Time_Diffrence_m4_U_V =sbs_gemPR_m4_clust_clustu_time[n] - sbs_gemPR_m4_clust_clustv_time[n1];
h_m4_UV->Fill(sbs_gemPR_m4_clust_clustu_time[n],sbs_gemPR_m4_clust_clustv_time[n1]);
h_m4_U_V->Fill(Time_Diffrence_m4_U_V);
}}
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
double Time_Diffrence_m5_U_V =sbs_gemPR_m5_clust_clustu_time[o] - sbs_gemPR_m5_clust_clustv_time[o1];
h_m5_UV->Fill(sbs_gemPR_m5_clust_clustu_time[o],sbs_gemPR_m5_clust_clustv_time[o1]);
h_m5_U_V->Fill(Time_Diffrence_m5_U_V);
}}
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
double Time_Diffrence_m6_U_V =sbs_gemPR_m6_clust_clustu_time[p] - sbs_gemPR_m6_clust_clustv_time[p1];
h_m6_UV->Fill(sbs_gemPR_m6_clust_clustu_time[p],sbs_gemPR_m6_clust_clustv_time[p1]);
h_m6_U_V->Fill(Time_Diffrence_m6_U_V);
}}
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
double Time_Diffrence_m7_U_V =sbs_gemPR_m7_clust_clustu_time[q] - sbs_gemPR_m7_clust_clustv_time[q1];
h_m7_UV->Fill(sbs_gemPR_m7_clust_clustu_time[q],sbs_gemPR_m7_clust_clustv_time[q1]);
h_m7_U_V->Fill(Time_Diffrence_m7_U_V);
}}

//UVm per module
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_adc; j++){
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
  double Time_Diffrence_m0_U_V =sbs_gemPR_m0_clust_clustu_pos[j] - sbs_gemPR_m0_clust_clustv_pos[j1];
h_m0_UVm->Fill(sbs_gemPR_m0_clust_clustu_pos[j],sbs_gemPR_m0_clust_clustv_pos[j1]);
h_m0_Um_Vm->Fill(Time_Diffrence_m0_U_V);
}}
for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
  double Time_Diffrence_m1_U_V =sbs_gemPR_m1_clust_clustu_pos[k] - sbs_gemPR_m1_clust_clustv_pos[k1];
h_m1_UVm->Fill(sbs_gemPR_m1_clust_clustu_pos[k],sbs_gemPR_m1_clust_clustv_pos[k1]);
h_m1_Um_Vm->Fill(Time_Diffrence_m1_U_V);
 }}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
double Time_Diffrence_m2_U_V =sbs_gemPR_m2_clust_clustu_pos[l] - sbs_gemPR_m2_clust_clustv_pos[l1];
h_m2_UVm->Fill(sbs_gemPR_m2_clust_clustu_pos[l],sbs_gemPR_m2_clust_clustv_pos[l1]);
h_m2_Um_Vm->Fill(Time_Diffrence_m2_U_V);
}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
double Time_Diffrence_m3_U_V =sbs_gemPR_m3_clust_clustu_pos[m] - sbs_gemPR_m3_clust_clustv_pos[m1];
h_m3_UVm->Fill(sbs_gemPR_m3_clust_clustu_pos[m],sbs_gemPR_m3_clust_clustv_pos[m1]);
h_m3_Um_Vm->Fill(Time_Diffrence_m3_U_V);
}}
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_adc; n++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
double Time_Diffrence_m4_U_V =sbs_gemPR_m4_clust_clustu_pos[n] - sbs_gemPR_m4_clust_clustv_pos[n1];
h_m4_UVm->Fill(sbs_gemPR_m4_clust_clustu_pos[n],sbs_gemPR_m4_clust_clustv_pos[n1]);
h_m4_Um_Vm->Fill(Time_Diffrence_m4_U_V);
}}
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
double Time_Diffrence_m5_U_V =sbs_gemPR_m5_clust_clustu_pos[o] - sbs_gemPR_m5_clust_clustv_pos[o1];
h_m5_UVm->Fill(sbs_gemPR_m5_clust_clustu_pos[o],sbs_gemPR_m5_clust_clustv_pos[o1]);
h_m5_Um_Vm->Fill(Time_Diffrence_m5_U_V);
}}
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
double Time_Diffrence_m6_U_V =sbs_gemPR_m6_clust_clustu_pos[p] - sbs_gemPR_m6_clust_clustv_pos[p1];
h_m6_UVm->Fill(sbs_gemPR_m6_clust_clustu_pos[p],sbs_gemPR_m6_clust_clustv_pos[p1]);
h_m6_Um_Vm->Fill(Time_Diffrence_m6_U_V);
}}
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
double Time_Diffrence_m7_U_V =sbs_gemPR_m7_clust_clustu_pos[q] - sbs_gemPR_m7_clust_clustv_pos[q1];
h_m7_UVm->Fill(sbs_gemPR_m7_clust_clustu_pos[q],sbs_gemPR_m7_clust_clustv_pos[q1]);
h_m7_Um_Vm->Fill(Time_Diffrence_m7_U_V);
}}


//Condition Apply for Both layer have Hits on U Strips
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_time; j++){
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_time; n++){
for (int j1=0; j1< Ndata_sbs_hodoPR_adc_a; j1++){
for (int j3=0; j3< Ndata_sbs_hodoPR_adc_adcelemID; j3++){
//if (sbs_gemPR_m0_clust_clustu_time[j]>0 && sbs_gemPR_m4_clust_clustu_time[n]>0){
//if (sbs_hodoPR_adc_a_time[j1]>0 && sbs_hodoPR_adc_adcelemID[j3]>0 ){
double Time_Diffrence_m0m4_U =sbs_gemPR_m0_clust_clustu_time[j] - sbs_gemPR_m4_clust_clustu_time[n];
if (std::fabs(Time_Diffrence_m0m4_U) < 10) {
if (std::fabs(sbs_hodoPR_adc_a_time[j1]) >= 16 && std::fabs(sbs_hodoPR_adc_a_time[j1]) <= 23) { 
hPRhodoVsPRGEMHits_m0m4_U->Fill( sbs_hodoPR_adc_a_time[j1],Time_Diffrence_m0m4_U);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U->Fill(sbs_hodoPR_adc_adcelemID[j3], Time_Diffrence_m0m4_U);
}}}}}}

for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
for (int k1=0; k1< Ndata_sbs_hodoPR_adc_a; k1++){
for (int k3=0; k3< Ndata_sbs_hodoPR_adc_adcelemID; k3++){
if (sbs_gemPR_m1_clust_clustu_time[k]>0 && sbs_gemPR_m5_clust_clustu_time[o]>0 && sbs_hodoPR_adc_a_time[k1]>0 && sbs_hodoPR_adc_adcelemID[k3]>0) {
double Time_Diffrence_m1m5_U =sbs_gemPR_m1_clust_clustu_time[k] - sbs_gemPR_m5_clust_clustu_time[o];
if (std::fabs(Time_Diffrence_m1m5_U) < 10) {
hPRhodoVsPRGEMHits_m1m5_U->Fill(sbs_hodoPR_adc_a_time[k1], Time_Diffrence_m1m5_U);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U->Fill(sbs_hodoPR_adc_adcelemID[k3], Time_Diffrence_m1m5_U);
}}}}}}

for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
for (int l1=0; l1<Ndata_sbs_hodoPR_adc_a; l1++){
for (int l3=0; l3< Ndata_sbs_hodoPR_adc_adcelemID; l3++){
if (sbs_gemPR_m2_clust_clustu_time[l]>0 && sbs_gemPR_m6_clust_clustu_time[p]>0 && sbs_hodoPR_adc_a_time[l1]>0 && sbs_hodoPR_adc_adcelemID[l3]>0){
double Time_Diffrence_m2m6_U =sbs_gemPR_m2_clust_clustu_time[l] - sbs_gemPR_m6_clust_clustu_time[p];
if (std::fabs(Time_Diffrence_m2m6_U) < 10) {
hPRhodoVsPRGEMHits_m2m6_U->Fill(sbs_hodoPR_adc_a_time[l1], Time_Diffrence_m2m6_U);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U->Fill(sbs_hodoPR_adc_adcelemID[l3], Time_Diffrence_m2m6_U);
}}}}}}

for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
for (int m1=0; m1< Ndata_sbs_hodoPR_adc_a; m1++){
for (int m3=0; m3< Ndata_sbs_hodoPR_adc_adcelemID; m3++){
if (sbs_gemPR_m3_clust_clustu_time[m]>0 && sbs_gemPR_m7_clust_clustu_time[q]>0 && sbs_hodoPR_adc_a_time[m1]>0 && sbs_hodoPR_adc_adcelemID[m3]>0){
double Time_Diffrence_m3m7_U =sbs_gemPR_m3_clust_clustu_time[m] - sbs_gemPR_m7_clust_clustu_time[q];
if (std::fabs(Time_Diffrence_m3m7_U) < 10) {
hPRhodoVsPRGEMHits_m3m7_U->Fill(sbs_hodoPR_adc_a_time[m1], Time_Diffrence_m3m7_U);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U->Fill(sbs_hodoPR_adc_adcelemID[m3], Time_Diffrence_m3m7_U);
}}}}}}
//Condition Apply for Both layer have Hits on V Strips
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
for (int j2=0; j2< Ndata_sbs_hodoPR_adc_a; j2++){
for (int j3=0; j3< Ndata_sbs_hodoPR_adc_adcelemID; j3++){
if (sbs_gemPR_m0_clust_clustv_time[j1]>0 && sbs_gemPR_m4_clust_clustv_time[n1]>0){
if (sbs_hodoPR_adc_a_time[j2]>0 && sbs_hodoPR_adc_adcelemID[j3]>0){
double Time_Diffrence_m0m4_V =sbs_gemPR_m0_clust_clustv_time[j1] - sbs_gemPR_m4_clust_clustv_time[n1];
if (std::fabs(Time_Diffrence_m0m4_V) < 10) {
hPRhodoVsPRGEMHits_m0m4_V->Fill(sbs_hodoPR_adc_a_time[j2],Time_Diffrence_m0m4_V);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V->Fill(sbs_hodoPR_adc_adcelemID[j3], Time_Diffrence_m0m4_V);
}}}}}}}
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
for (int k2=0; k2< Ndata_sbs_hodoPR_adc_a; k2++){
for (int k3=0; k3< Ndata_sbs_hodoPR_adc_adcelemID; k3++){
if (sbs_gemPR_m1_clust_clustv_time[k1]>0 && sbs_gemPR_m5_clust_clustv_time[o1]>0 && sbs_hodoPR_adc_a_time[k2]>0 &&sbs_hodoPR_adc_adcelemID[k3]>0) {
double Time_Diffrence_m1m5_V =sbs_gemPR_m1_clust_clustv_time[k1] - sbs_gemPR_m5_clust_clustv_time[o1];
if (std::fabs(Time_Diffrence_m1m5_V) < 10) {
hPRhodoVsPRGEMHits_m1m5_V->Fill(sbs_hodoPR_adc_a_time[k2], Time_Diffrence_m1m5_V);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V->Fill(sbs_hodoPR_adc_adcelemID[k3], Time_Diffrence_m1m5_V);
}}}}}}
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
for (int l2=0; l2<Ndata_sbs_hodoPR_adc_a; l2++){
for (int l3=0; l3< Ndata_sbs_hodoPR_adc_adcelemID; l3++){
if (sbs_gemPR_m2_clust_clustv_time[l1]>0 && sbs_gemPR_m6_clust_clustv_time[p1]>0 && sbs_hodoPR_adc_a_time[l2]>0 &&sbs_hodoPR_adc_adcelemID[l3]>0){
double Time_Diffrence_m2m6_V =sbs_gemPR_m2_clust_clustv_time[l1] - sbs_gemPR_m6_clust_clustv_time[p1];
if (std::fabs(Time_Diffrence_m2m6_V) < 10) {
hPRhodoVsPRGEMHits_m2m6_V->Fill(sbs_hodoPR_adc_a_time[l2], Time_Diffrence_m2m6_V);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V->Fill(sbs_hodoPR_adc_adcelemID[l3], Time_Diffrence_m2m6_V);
}}}}}}
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
for (int m2=0; m2< Ndata_sbs_hodoPR_adc_a; m2++){
for (int m3=0; m3< Ndata_sbs_hodoPR_adc_adcelemID; m3++){
if (sbs_gemPR_m3_clust_clustv_time[m1]>0 && sbs_gemPR_m7_clust_clustv_time[q1]>0 && sbs_hodoPR_adc_a_time[m2]>0 && sbs_hodoPR_adc_adcelemID[m3]>0){
double Time_Diffrence_m3m7_V =sbs_gemPR_m3_clust_clustv_time[m1] - sbs_gemPR_m7_clust_clustv_time[q1];
if (std::fabs(Time_Diffrence_m3m7_V) < 10) {
hPRhodoVsPRGEMHits_m3m7_V->Fill(sbs_hodoPR_adc_a_time[m2], Time_Diffrence_m3m7_V);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V->Fill(sbs_hodoPR_adc_adcelemID[m3], Time_Diffrence_m3m7_V);
}}}}}}


// For active Analyzer 
//Condition Apply for Both layer have Hits on U Strips
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_adc; j++){
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_adc; n++){
for (int j1=0; j1< Ndata_sbs_activeAna_adc_a; j1++){
if (sbs_gemPR_m0_clust_clustu_time[j]>0 && sbs_gemPR_m4_clust_clustu_time[n]>0 && sbs_activeAna_adc_a_time[j1]>0) {
double Time_Diffrence_m0m4_U =sbs_gemPR_m0_clust_clustu_time[j] - sbs_gemPR_m4_clust_clustu_time[n];
if (std::fabs(Time_Diffrence_m0m4_U) < 10) {
hactiveAnaVsPRGEMHits_m0m4_U->Fill( sbs_activeAna_adc_a_time[j1],Time_Diffrence_m0m4_U);
}}}}}
for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
for (int k1=0; k1< Ndata_sbs_activeAna_adc_a; k1++){
if (sbs_gemPR_m1_clust_clustu_time[k]>0 && sbs_gemPR_m5_clust_clustu_time[o]>0 && sbs_activeAna_adc_a_time[k1]>0) {
double Time_Diffrence_m1m5_U =sbs_gemPR_m1_clust_clustu_time[k] - sbs_gemPR_m5_clust_clustu_time[o];
if (std::fabs(Time_Diffrence_m1m5_U) < 10) {
hactiveAnaVsPRGEMHits_m1m5_U->Fill(sbs_activeAna_adc_a_time[k1],Time_Diffrence_m1m5_U);
}}}}}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
for (int l1=0; l1<Ndata_sbs_activeAna_adc_a; l1++){
if (sbs_gemPR_m2_clust_clustu_time[l]>0 && sbs_gemPR_m6_clust_clustu_time[p]>0 && sbs_activeAna_adc_a_time[l1]>0){
double Time_Diffrence_m2m6_U =sbs_gemPR_m2_clust_clustu_time[l] - sbs_gemPR_m6_clust_clustu_time[p];
if (std::fabs(Time_Diffrence_m2m6_U) < 10) {
hactiveAnaVsPRGEMHits_m2m6_U->Fill(sbs_activeAna_adc_a_time[l1],Time_Diffrence_m2m6_U);
}}}}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
for (int m1=0; m1< Ndata_sbs_activeAna_adc_a; m1++){
if (sbs_gemPR_m3_clust_clustu_time[m]>0 && sbs_gemPR_m7_clust_clustu_time[q]>0 && sbs_activeAna_adc_a_time[m1]>0){
double Time_Diffrence_m3m7_U =sbs_gemPR_m3_clust_clustu_time[m] - sbs_gemPR_m7_clust_clustu_time[q];
if (std::fabs(Time_Diffrence_m3m7_U) < 10) {
hactiveAnaVsPRGEMHits_m3m7_U->Fill(sbs_activeAna_adc_a_time[m1],Time_Diffrence_m3m7_U);
}}}}}
//Condition Apply for Both layer have Hits on V Strips
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
for (int j2=0; j2< Ndata_sbs_activeAna_adc_a; j2++){
if (sbs_gemPR_m0_clust_clustv_time[j1]>0 && sbs_gemPR_m4_clust_clustv_time[n1]>0 && sbs_activeAna_adc_a_time[j2]>0 ){
double Time_Diffrence_m0m4_V =sbs_gemPR_m0_clust_clustv_time[j1] - sbs_gemPR_m4_clust_clustv_time[n1];
if (std::fabs(Time_Diffrence_m0m4_V) < 10) {
hactiveAnaVsPRGEMHits_m0m4_V->Fill( sbs_activeAna_adc_a_time[j2],Time_Diffrence_m0m4_V);
}}}}}
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
for (int k2=0; k2< Ndata_sbs_activeAna_adc_a; k2++){
if (sbs_gemPR_m1_clust_clustv_time[k1]>0 && sbs_gemPR_m5_clust_clustv_time[o1]>0 && sbs_activeAna_adc_a_time[k2]>0) {
double Time_Diffrence_m1m5_V =sbs_gemPR_m1_clust_clustv_time[k1] - sbs_gemPR_m5_clust_clustv_time[o1];
if (std::fabs(Time_Diffrence_m1m5_V) < 10) {
hactiveAnaVsPRGEMHits_m1m5_V->Fill(sbs_activeAna_adc_a_time[k2],Time_Diffrence_m1m5_V);
}}}}}
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
for (int l2=0; l2<Ndata_sbs_activeAna_adc_a; l2++){
if (sbs_gemPR_m2_clust_clustv_time[l1]>0 && sbs_gemPR_m6_clust_clustv_time[p1]>0 && sbs_activeAna_adc_a_time[l2]>0) {
double Time_Diffrence_m2m6_V =sbs_gemPR_m2_clust_clustv_time[l1] - sbs_gemPR_m6_clust_clustv_time[p1];
if (std::fabs(Time_Diffrence_m2m6_V) < 10) {
hactiveAnaVsPRGEMHits_m2m6_V->Fill(sbs_activeAna_adc_a_time[l2],Time_Diffrence_m2m6_V);
}}}}}
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
for (int m2=0; m2< Ndata_sbs_activeAna_adc_a; m2++){
if (sbs_gemPR_m3_clust_clustv_time[m1]>0 && sbs_gemPR_m7_clust_clustv_time[q1]>0 && sbs_activeAna_adc_a_time[m2]>0){
double Time_Diffrence_m3m7_V =sbs_gemPR_m3_clust_clustv_time[m1] - sbs_gemPR_m7_clust_clustv_time[q1];
if (std::fabs(Time_Diffrence_m3m7_V) < 10) {
hactiveAnaVsPRGEMHits_m3m7_V->Fill(sbs_activeAna_adc_a_time[m2],Time_Diffrence_m3m7_V);
}}}}}

}

TCanvas *C = new TCanvas("C", "PR_Hodoscope_Time vs GEMPR_ClustU_Time", 1200, 600);
C->Divide(4,2);
C->cd(1);
h_m0m4_U->SetXTitle("GEMPR_m0 Clustu_Time");
h_m0m4_U->SetYTitle("GEMPR_m4 Clustu_Time");
h_m0m4_U->Draw("COLZ");
C->cd(2);
h_m1m5_U->SetXTitle("GEMPR_m1 Clustu_Time");
h_m1m5_U->SetYTitle("GEMPR_m5 Clustu_Time");
h_m1m5_U->Draw("COLZ");
C->cd(3);
h_m2m6_U->SetXTitle("GEMPR_m2 Clustu_Time");
h_m2m6_U->SetYTitle("GEMPR_m6 Clustu_Time");
h_m2m6_U->Draw("COLZ");
C->cd(4);
h_m3m7_U->SetXTitle("GEMPR_m3 Clustu_Time");
h_m3m7_U->SetYTitle("GEMPR_m7 Clustu_Time");
h_m3m7_U->Draw("COLZ");
C->cd(5);
h_m0m4_V->SetXTitle("GEMPR_m0 Clustv_Time");
h_m0m4_V->SetYTitle("GEMPR_m4 Clustv_Time");
h_m0m4_V->Draw("COLZ");
C->cd(6);
h_m1m5_V->SetXTitle("GEMPR_m1 Clustv_Time");
h_m1m5_V->SetYTitle("GEMPR_m5 Clustv_Time");
h_m1m5_V->Draw("COLZ");
C->cd(7);
h_m2m6_V->SetXTitle("GEMPR_m2 Clustv_Time");
h_m2m6_V->SetYTitle("GEMPR_m6 Clustv_Time");
h_m2m6_V->Draw("COLZ");
C->cd(8);
h_m3m7_V->SetXTitle("GEMPR_m3 Clustv_Time");
h_m3m7_V->SetYTitle("GEMPR_m7 Clustv_Time");
h_m3m7_V->Draw("COLZ");

TCanvas *Cm = new TCanvas("Cm", "GEMPR_ClustU and V_position", 1200, 600);
Cm->Divide(4,2);
Cm->cd(1);
h_m0m4_Um->SetXTitle("GEMPR_m0 Clustu_pos");
h_m0m4_Um->SetYTitle("GEMPR_m4 Clustu_pos");
h_m0m4_Um->Draw("COLZ");
Cm->cd(2);
h_m1m5_Um->SetXTitle("GEMPR_m1 Clustu_pos");
h_m1m5_Um->SetYTitle("GEMPR_m5 Clustu_pos");
h_m1m5_Um->Draw("COLZ");
Cm->cd(3);
h_m2m6_Um->SetXTitle("GEMPR_m2 Clustu_pos");
h_m2m6_Um->SetYTitle("GEMPR_m6 Clustu_pos");
h_m2m6_Um->Draw("COLZ");
Cm->cd(4);
h_m3m7_Um->SetXTitle("GEMPR_m3 Clustu_pos");
h_m3m7_Um->SetYTitle("GEMPR_m7 Clustu_pos");
h_m3m7_Um->Draw("COLZ");
Cm->cd(5);
h_m0m4_Vm->SetXTitle("GEMPR_m0 Clustv_pos");
h_m0m4_Vm->SetYTitle("GEMPR_m4 Clustv_pos");
h_m0m4_Vm->Draw("COLZ");
Cm->cd(6);
h_m1m5_Vm->SetXTitle("GEMPR_m1 Clustv_pos");
h_m1m5_Vm->SetYTitle("GEMPR_m5 Clustv_pos");
h_m1m5_Vm->Draw("COLZ");
Cm->cd(7);
h_m2m6_Vm->SetXTitle("GEMPR_m2 Clustv_pos");
h_m2m6_Vm->SetYTitle("GEMPR_m6 Clustv_pos");
h_m2m6_Vm->Draw("COLZ");
Cm->cd(8);
h_m3m7_Vm->SetXTitle("GEMPR_m3 Clustv_pos");
h_m3m7_Vm->SetYTitle("GEMPR_m7 Clustv_pos");
h_m3m7_Vm->Draw("COLZ");

TCanvas *CC = new TCanvas("CC", "PR_Hodoscope_Time vs GEMPR_ClustUV_Time", 1200, 600);
CC->Divide(4,2);
CC->cd(1);
h_m0_UV->SetXTitle("GEMPR_m0 Clustu_Time");
h_m0_UV->SetYTitle("GEMPR_m0 Clustv_Time");
h_m0_UV->Draw("COLZ");
CC->cd(2);
h_m1_UV->SetXTitle("GEMPR_m1 Clustu_Time");
h_m1_UV->SetYTitle("GEMPR_m1 Clustv_Time");
h_m1_UV->Draw("COLZ");
CC->cd(3);
h_m2_UV->SetXTitle("GEMPR_m2 Clustu_Time");
h_m2_UV->SetYTitle("GEMPR_m2 Clustv_Time");
h_m2_UV->Draw("COLZ");
CC->cd(4);
h_m3_UV->SetXTitle("GEMPR_m3 Clustu_Time");
h_m3_UV->SetYTitle("GEMPR_m3 Clustv_Time");
h_m3_UV->Draw("COLZ");
CC->cd(5);
h_m4_UV->SetXTitle("GEMPR_m4 Clustu_Time");
h_m4_UV->SetYTitle("GEMPR_m4 Clustv_Time");
h_m4_UV->Draw("COLZ");
CC->cd(6);
h_m5_UV->SetXTitle("GEMPR_m5 Clustu_Time");
h_m5_UV->SetYTitle("GEMPR_m5 Clustv_Time");
h_m5_UV->Draw("COLZ");
CC->cd(7);
h_m6_UV->SetXTitle("GEMPR_m6 Clustu_Time");
h_m6_UV->SetYTitle("GEMPR_m6 Clustv_Time");
h_m6_UV->Draw("COLZ");
CC->cd(8);
h_m7_UV->SetXTitle("GEMPR_m7 Clustu_Time");
h_m7_UV->SetYTitle("GEMPR_m7 Clustv_Time");
h_m7_UV->Draw("COLZ");

TCanvas *CCc = new TCanvas("CCc", "GEMPR_ClustUV_position", 1200, 600);
CCc->Divide(4,2);
CCc->cd(1);
h_m0_UVm->SetXTitle("GEMPR_m0 Clustu_pos");
h_m0_UVm->SetYTitle("GEMPR_m0 Clustv_pos");
h_m0_UVm->Draw("COLZ");
CCc->cd(2);
h_m1_UVm->SetXTitle("GEMPR_m1 Clustu_pos");
h_m1_UVm->SetYTitle("GEMPR_m1 Clustv_pos");
h_m1_UVm->Draw("COLZ");
CCc->cd(3);
h_m2_UVm->SetXTitle("GEMPR_m2 Clustu_pos");
h_m2_UVm->SetYTitle("GEMPR_m2 Clustv_pos");
h_m2_UVm->Draw("COLZ");
CCc->cd(4);
h_m3_UVm->SetXTitle("GEMPR_m3 Clustu_pos");
h_m3_UVm->SetYTitle("GEMPR_m3 Clustv_pos");
h_m3_UVm->Draw("COLZ");
CCc->cd(5);
h_m4_UVm->SetXTitle("GEMPR_m4 Clustu_pos");
h_m4_UVm->SetYTitle("GEMPR_m4 Clustv_pos");
h_m4_UVm->Draw("COLZ");
CCc->cd(6);
h_m5_UVm->SetXTitle("GEMPR_m5 Clustu_pos");
h_m5_UVm->SetYTitle("GEMPR_m5 Clustv_pos");
h_m5_UVm->Draw("COLZ");
CCc->cd(7);
h_m6_UVm->SetXTitle("GEMPR_m6 Clustu_pos");
h_m6_UVm->SetYTitle("GEMPR_m6 Clustv_pos");
h_m6_UVm->Draw("COLZ");
CCc->cd(8);
h_m7_UVm->SetXTitle("GEMPR_m7 Clustu_pos");
h_m7_UVm->SetYTitle("GEMPR_m7 Clustv_pos");
h_m7_UVm->Draw("COLZ");


TCanvas *CCC = new TCanvas("CCC", " GEMPR_ClustU_Time_Difference and V_Time_Differenece", 1200, 600);
CCC->Divide(4,2);
CCC->cd(1);
h_m0_m4_U->SetXTitle("GEMPR_m0-m4 Clustu_Time_Difference");
h_m0_m4_U->Draw("HIST");
CCC->cd(2);
h_m1_m5_U->SetXTitle("GEMPR_m1-m5 Clustu_Time_Difference");
h_m1_m5_U->Draw("HIST");
CCC->cd(3);
h_m2_m6_U->SetXTitle("GEMPR_m2-m6 Clustu_Time_Difference");
h_m2_m6_U->Draw("HIST");
CCC->cd(4);
h_m3_m7_U->SetXTitle("GEMPR_m3-m7 Clustu_Time_Difference");
h_m3_m7_U->Draw("HIST");
CCC->cd(5);
h_m0_m4_V->SetXTitle("GEMPR_m0-m4 Clustv_Time_Difference");
h_m0_m4_V->Draw("HIST");
CCC->cd(6);
h_m1_m5_V->SetXTitle("GEMPR_m1-m5 Clustv_Time_Difference");
h_m1_m5_V->Draw("HIST");
CCC->cd(7);
h_m2_m6_V->SetXTitle("GEMPR_m2-m6 Clustv_Time_Difference");
h_m2_m6_V->Draw("HIST");
CCC->cd(8);
h_m3_m7_V->SetXTitle("GEMPR_m3-m7 Clustv_Time_Difference");
h_m3_m7_V->Draw("HIST");

TCanvas *CCCC = new TCanvas("CCCC", " GEMPR_ClustU_strips_Difference and V_strips_Differenece", 1200, 600);
CCCC->Divide(4,2);
CCCC->cd(1);
h_m0_m4_Um->SetXTitle("GEMPR_m0-m4 Clustu_position_Difference");
h_m0_m4_Um->Draw("HIST");
CCCC->cd(2);
h_m1_m5_Um->SetXTitle("GEMPR_m1-m5 Clustu_position_Difference");
h_m1_m5_Um->Draw("HIST");
CCCC->cd(3);
h_m2_m6_Um->SetXTitle("GEMPR_m2-m6 Clustu_position_Difference");
h_m2_m6_Um->Draw("HIST");
CCCC->cd(4);
h_m3_m7_Um->SetXTitle("GEMPR_m3-m7 Clustu_position_Difference");
h_m3_m7_Um->Draw("HIST");
CCCC->cd(5);
h_m0_m4_Vm->SetXTitle("GEMPR_m0-m4 Clustv_position_Difference");
h_m0_m4_Vm->Draw("HIST");
CCCC->cd(6);
h_m1_m5_Vm->SetXTitle("GEMPR_m1-m5 Clustv_position_Difference");
h_m1_m5_Vm->Draw("HIST");
CCCC->cd(7);
h_m2_m6_Vm->SetXTitle("GEMPR_m2-m6 Clustv_position_Difference");
h_m2_m6_Vm->Draw("HIST");
CCCC->cd(8);
h_m3_m7_Vm->SetXTitle("GEMPR_m3-m7 Clustv_position_Difference");
h_m3_m7_Vm->Draw("HIST");

TCanvas *cC = new TCanvas("cC", " GEMPR_(U-V)_Time_Differenece", 1200, 600);
cC->Divide(4,2);
cC->cd(1);
h_m0_U_V->SetXTitle("GEMPR_m0 Clust(U-V)_Time_Difference");
h_m0_U_V->Draw("HIST");
cC->cd(2);
h_m1_U_V->SetXTitle("GEMPR_m1 Clust(U-V)_Time_Difference");
h_m1_U_V->Draw("HIST");
cC->cd(3);
h_m2_U_V->SetXTitle("GEMPR_m2 Clust(U-V)_Time_Difference");
h_m2_U_V->Draw("HIST");
cC->cd(4);
h_m3_U_V->SetXTitle("GEMPR_m3 Clust(U-V)_Time_Difference");
h_m3_U_V->Draw("HIST");
cC->cd(5);
h_m4_U_V->SetXTitle("GEMPR_m4 Clust(U-V)_Time_Difference");
h_m4_U_V->Draw("HIST");
cC->cd(6);
h_m5_U_V->SetXTitle("GEMPR_m5 Clust(U-V)_Time_Difference");
h_m5_U_V->Draw("HIST");
cC->cd(7);
h_m6_U_V->SetXTitle("GEMPR_m6 Clust(U-V)_Time_Difference");
h_m6_U_V->Draw("HIST");
cC->cd(8);
h_m7_U_V->SetXTitle("GEMPR_m7 Clust(U-V)_Time_Difference");
h_m7_U_V->Draw("HIST");

TCanvas *ccC = new TCanvas("ccC", " GEMPR_(Um-Vm)_Position_Differenece", 1200, 600);
ccC->Divide(4,2);
ccC->cd(1);
h_m0_Um_Vm->SetXTitle("GEMPR_m0 Clust(U-V)_Time_Difference");
h_m0_Um_Vm->Draw("HIST");
ccC->cd(2);
h_m1_Um_Vm->SetXTitle("GEMPR_m1 Clust(U-V)_Time_Difference");
h_m1_Um_Vm->Draw("HIST");
ccC->cd(3);
h_m2_Um_Vm->SetXTitle("GEMPR_m2 Clust(U-V)_Time_Difference");
h_m2_Um_Vm->Draw("HIST");
ccC->cd(4);
h_m3_Um_Vm->SetXTitle("GEMPR_m3 Clust(U-V)_Time_Difference");
h_m3_Um_Vm->Draw("HIST");
ccC->cd(5);
h_m4_Um_Vm->SetXTitle("GEMPR_m4 Clust(U-V)_Time_Difference");
h_m4_Um_Vm->Draw("HIST");
ccC->cd(6);
h_m5_Um_Vm->SetXTitle("GEMPR_m5 Clust(U-V)_Time_Difference");
h_m5_Um_Vm->Draw("HIST");
ccC->cd(7);
h_m6_Um_Vm->SetXTitle("GEMPR_m6 Clust(U-V)_Time_Difference");
h_m6_Um_Vm->Draw("HIST");
ccC->cd(8);
h_m7_Um_Vm->SetXTitle("GEMPR_m7 Clust(U-V)_Time_Difference");
h_m7_Um_Vm->Draw("HIST");

TCanvas* Cccanvas = new TCanvas("Cccanvas", "PRhodo Time vs PRGEM Hits", 800, 600);
Cccanvas->Divide(4,2);
Cccanvas->cd(1);
hPRhodoVsPRGEMHits_m0m4_Um->Draw("COLZ");
hPRhodoVsPRGEMHits_m0m4_Um->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m0m4_Um->SetYTitle("position on module_m0m4_Um");
Cccanvas->cd(2);
hPRhodoVsPRGEMHits_m1m5_Um->Draw("COLZ");
hPRhodoVsPRGEMHits_m1m5_Um->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m1m5_Um->SetYTitle("position on module_m1m5_Um");
Cccanvas->cd(3);
hPRhodoVsPRGEMHits_m2m6_Um->Draw("COLZ");
hPRhodoVsPRGEMHits_m2m6_Um->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m2m6_Um->SetYTitle("position on module_m2m6_Um");
Cccanvas->cd(4);
hPRhodoVsPRGEMHits_m3m7_Um->Draw("COLZ");
hPRhodoVsPRGEMHits_m3m7_Um->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m3m7_Um->SetYTitle("position on module_m3m7_Um");
Cccanvas->cd(5);
hPRhodoVsPRGEMHits_m0m4_Vm->Draw("COLZ");
hPRhodoVsPRGEMHits_m0m4_Vm->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m0m4_Vm->SetYTitle("position on module_m0m4_Vm");
Cccanvas->cd(6);
hPRhodoVsPRGEMHits_m1m5_Vm->Draw("COLZ");
hPRhodoVsPRGEMHits_m1m5_Vm->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m1m5_Vm->SetYTitle("position on module_m1m5_Vm");
Cccanvas->cd(7);
hPRhodoVsPRGEMHits_m2m6_Vm->Draw("COLZ");
hPRhodoVsPRGEMHits_m2m6_Vm->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m2m6_Vm->SetYTitle("position on module_m2m6_Vm");
Cccanvas->cd(8);
hPRhodoVsPRGEMHits_m3m7_Vm->Draw("COLZ");
hPRhodoVsPRGEMHits_m3m7_Vm->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m3m7_Vm->SetYTitle("position on module_m3m7_Vm");

TCanvas* ccanvas = new TCanvas("ccanvas", "PRhodo Time vs PRGEM Hits", 800, 600);
ccanvas->Divide(4,2);
ccanvas->cd(1);
hPRhodoVsPRGEMHits_m0m4_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m0m4_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m0m4_U->SetYTitle("Hits on module_m0m4_U");
ccanvas->cd(2);
hPRhodoVsPRGEMHits_m1m5_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m1m5_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m1m5_U->SetYTitle("Hits on module_m1m5_U");
ccanvas->cd(3);
hPRhodoVsPRGEMHits_m2m6_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m2m6_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m2m6_U->SetYTitle("Hits on module_m2m6_U");
ccanvas->cd(4);
hPRhodoVsPRGEMHits_m3m7_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m3m7_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m3m7_U->SetYTitle("Hits on module_m3m7_U");
ccanvas->cd(5);
hPRhodoVsPRGEMHits_m0m4_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m0m4_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m0m4_V->SetYTitle("Hits on module_m0m4_V");
ccanvas->cd(6);
hPRhodoVsPRGEMHits_m1m5_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m1m5_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m1m5_V->SetYTitle("Hits on module_m1m5_V");
ccanvas->cd(7);
hPRhodoVsPRGEMHits_m2m6_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m2m6_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m2m6_V->SetYTitle("Hits on module_m2m6_V");
ccanvas->cd(8);
hPRhodoVsPRGEMHits_m3m7_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m3m7_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m3m7_V->SetYTitle("Hits on module_m3m7_V");

TCanvas* canvas = new TCanvas("canvas", "PRhodo_adc_adcelemID vs PRGEM Hits", 800, 600);
canvas->Divide(4,2);
canvas->cd(1);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U->SetYTitle("Hits on module_m0m4_U");
canvas->cd(2);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U->SetYTitle("Hits on module_m1m5_U");
canvas->cd(3);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U->SetYTitle("Hits on module_m2m6_U");
canvas->cd(4);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U->SetYTitle("Hits on module_m3m7_U");
canvas->cd(5);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V->SetYTitle("Hits on module_m0m4_V");
canvas->cd(6);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V->SetYTitle("Hits on module_m1m5_V");
canvas->cd(7);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V->SetYTitle("Hits on module_m2m6_V");
canvas->cd(8);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V->Draw("COLZ");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V->SetXTitle("PRhodo_adc_adcelemID");
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V->SetYTitle("Hits on module_m3m7_V");
/*
//for Active Analyzer 
TCanvas* cc = new TCanvas("cc", "activeAna Time vs PRGEM_L1 Hits", 800, 600);
cc->Divide(4,2);
cc->cd(1);
hactiveAnaVsPRGEMHits_m0m4_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m0m4_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m0m4_U->SetYTitle("Hits on module_m0m4_U");
cc->cd(2);
hactiveAnaVsPRGEMHits_m1m5_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m1m5_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m1m5_U->SetYTitle("Hits on module_m1m5_U");
cc->cd(3);
hactiveAnaVsPRGEMHits_m2m6_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m2m6_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m2m6_U->SetYTitle("Hits on module_m2m6_U");
cc->cd(4);
hactiveAnaVsPRGEMHits_m3m7_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m3m7_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m3m7_U->SetYTitle("Hits on module_m3m7_U");
cc->cd(5);
hactiveAnaVsPRGEMHits_m0m4_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m0m4_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m0m4_V->SetYTitle("Hits on module_m0m4_V");
cc->cd(6);
hactiveAnaVsPRGEMHits_m1m5_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m1m5_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m1m5_V->SetYTitle("Hits on module_m1m5_V");
cc->cd(7);
hactiveAnaVsPRGEMHits_m2m6_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m2m6_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m2m6_V->SetYTitle("Hits on module_m2m6_V");
cc->cd(8);
hactiveAnaVsPRGEMHits_m3m7_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m3m7_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m3m7_V->SetYTitle("Hits on module_m3m7_V");

TCanvas* c = new TCanvas("c", "activeAna Time vs PRGEM_L2 Hits", 800, 600);
c->Divide(4,2);
c->cd(1);
hactiveAnaVsPRGEMHits_m4_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m4_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m4_U->SetYTitle("Hits on module_m4_U");
c->cd(2);
hactiveAnaVsPRGEMHits_m5_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m5_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m5_U->SetYTitle("Hits on module_m5_U");
c->cd(3);
hactiveAnaVsPRGEMHits_m6_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m6_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m6_U->SetYTitle("Hits on module_m6_U");
c->cd(4);
hactiveAnaVsPRGEMHits_m7_U->Draw("COLZ");
hactiveAnaVsPRGEMHits_m7_U->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m7_U->SetYTitle("Hits on module_m7_U");
c->cd(5);
hactiveAnaVsPRGEMHits_m4_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m4_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m4_V->SetYTitle("Hits on module_m4_V");
c->cd(6);
hactiveAnaVsPRGEMHits_m5_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m5_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m5_V->SetYTitle("Hits on module_m5_V");
c->cd(7);
hactiveAnaVsPRGEMHits_m6_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m6_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m6_V->SetYTitle("Hits on module_m6_V");
c->cd(8);
hactiveAnaVsPRGEMHits_m7_V->Draw("COLZ");
hactiveAnaVsPRGEMHits_m7_V->SetXTitle("activeAna_adc_Time");
hactiveAnaVsPRGEMHits_m7_V->SetYTitle("Hits on module_m7_V");
*/
}
