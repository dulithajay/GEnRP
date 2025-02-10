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

void PR_Multiplicity() {

 TChain *T = new TChain("T");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_5000_events.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_5000_events_1.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_5000_events_2.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_5000_events_3.root");

double sbs_hodoPR_adc_a[10000];
int Ndata_sbs_hodoPR_adc_a;
double sbs_hodoPR_adc_a_time[10000];
int Ndata_sbs_hodoPR_adc_a_time;
double sbs_hodoPR_adc_adcelemID[10000];
int Ndata_sbs_hodoPR_adc_adcelemID;


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

//For Multiplllicity
double sbs_gemPR_m1_clust_clustu_strips[10000];
double sbs_gemPR_m1_clust_clustv_strips[10000];
double sbs_gemPR_m0_clust_clustu_strips[10000];
double sbs_gemPR_m0_clust_clustv_strips[10000];
double sbs_gemPR_m2_clust_clustu_strips[10000];
double sbs_gemPR_m2_clust_clustv_strips[10000];
double sbs_gemPR_m3_clust_clustu_strips[10000];
double sbs_gemPR_m3_clust_clustv_strips[10000];
int Ndata_sbs_gemPR_m1_clust_clustu_strips;
int Ndata_sbs_gemPR_m1_clust_clustv_strips;
int Ndata_sbs_gemPR_m0_clust_clustu_strips;
int Ndata_sbs_gemPR_m0_clust_clustv_strips;
int Ndata_sbs_gemPR_m2_clust_clustu_strips;
int Ndata_sbs_gemPR_m2_clust_clustv_strips;
int Ndata_sbs_gemPR_m3_clust_clustu_strips;
int Ndata_sbs_gemPR_m3_clust_clustv_strips;
double sbs_gemPR_m4_clust_clustu_strips[10000];
double sbs_gemPR_m4_clust_clustv_strips[10000];
double sbs_gemPR_m5_clust_clustu_strips[10000];
double sbs_gemPR_m5_clust_clustv_strips[10000];
double sbs_gemPR_m6_clust_clustu_strips[10000];
double sbs_gemPR_m6_clust_clustv_strips[10000];
double sbs_gemPR_m7_clust_clustu_strips[10000];
double sbs_gemPR_m7_clust_clustv_strips[10000];
int Ndata_sbs_gemPR_m4_clust_clustu_strips;
int Ndata_sbs_gemPR_m4_clust_clustv_strips;
int Ndata_sbs_gemPR_m5_clust_clustu_strips;
int Ndata_sbs_gemPR_m5_clust_clustv_strips;
int Ndata_sbs_gemPR_m6_clust_clustu_strips;
int Ndata_sbs_gemPR_m6_clust_clustv_strips;
int Ndata_sbs_gemPR_m7_clust_clustu_strips;
int Ndata_sbs_gemPR_m7_clust_clustv_strips;

T->SetBranchAddress("sbs.hodoPR_adc.a", &sbs_hodoPR_adc_a);
T->SetBranchAddress("sbs.hodoPR_adc.a_time", &sbs_hodoPR_adc_a_time);
T->SetBranchAddress("sbs.hodoPR_adc.adcelemID", &sbs_hodoPR_adc_adcelemID);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.a_time", &Ndata_sbs_hodoPR_adc_a_time);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.a", &Ndata_sbs_hodoPR_adc_a);
T->SetBranchAddress("Ndata.sbs.hodoPR_adc.adcelemID", &Ndata_sbs_hodoPR_adc_adcelemID);

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


T->SetBranchAddress("sbs.gemPR.m0.clust.clustu_strips", &sbs_gemPR_m0_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m0.clust.clustv_strips", &sbs_gemPR_m0_clust_clustv_strips);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustu_strips", &sbs_gemPR_m1_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m1.clust.clustv_strips", &sbs_gemPR_m1_clust_clustv_strips);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustu_strips", &sbs_gemPR_m2_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m2.clust.clustv_strips", &sbs_gemPR_m2_clust_clustv_strips);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustu_strips", &sbs_gemPR_m3_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m3.clust.clustv_strips", &sbs_gemPR_m3_clust_clustv_strips);
T->SetBranchAddress("sbs.gemPR.m4.clust.clustu_strips", &sbs_gemPR_m4_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m4.clust.clustv_strips", &sbs_gemPR_m4_clust_clustv_strips);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustu_strips", &sbs_gemPR_m5_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m5.clust.clustv_strips", &sbs_gemPR_m5_clust_clustv_strips);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustu_strips", &sbs_gemPR_m6_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m6.clust.clustv_strips", &sbs_gemPR_m6_clust_clustv_strips);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustu_strips", &sbs_gemPR_m7_clust_clustu_strips);
T->SetBranchAddress("sbs.gemPR.m7.clust.clustv_strips", &sbs_gemPR_m7_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustu_strips", &Ndata_sbs_gemPR_m0_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.clust.clustv_strips", &Ndata_sbs_gemPR_m0_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustu_strips", &Ndata_sbs_gemPR_m1_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.clust.clustv_strips", &Ndata_sbs_gemPR_m1_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustu_strips", &Ndata_sbs_gemPR_m2_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.clust.clustv_strips", &Ndata_sbs_gemPR_m2_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustu_strips", &Ndata_sbs_gemPR_m3_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.clust.clustv_strips", &Ndata_sbs_gemPR_m3_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustu_strips", &Ndata_sbs_gemPR_m4_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.clust.clustv_strips", &Ndata_sbs_gemPR_m4_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustu_strips", &Ndata_sbs_gemPR_m5_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.clust.clustv_strips", &Ndata_sbs_gemPR_m5_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustu_strips", &Ndata_sbs_gemPR_m6_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.clust.clustv_strips", &Ndata_sbs_gemPR_m6_clust_clustv_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustu_strips", &Ndata_sbs_gemPR_m7_clust_clustu_strips);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.clust.clustv_strips", &Ndata_sbs_gemPR_m7_clust_clustv_strips);

TH2F *h_m0m4_Um = new TH2F("h_m0m4_Um","ClustU_strips_m0 vs  ClustU_strips_m4",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m1m5_Um = new TH2F("h_m1m5_Um","ClustU_strips_m1 vs  ClustU_strips_m5",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m2m6_Um = new TH2F("h_m2m6_Um","ClustU_strips_m2 vs  ClustU_strips_m6",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m3m7_Um = new TH2F("h_m3m7_Um","ClustU_strips_m3 vs  ClustU_strips_m7",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m0m4_Vm = new TH2F("h_m0m4_Vm","ClustV_strips_m0 vs  ClustV_strips_m4",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m1m5_Vm = new TH2F("h_m1m5_Vm","ClustV_strips_m1 vs  ClustV_strips_m5",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m2m6_Vm = new TH2F("h_m2m6_Vm","ClustV_strips_m2 vs  ClustV_strips_m6",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m3m7_Vm = new TH2F("h_m3m7_Vm","ClustV_strips_m3 vs  ClustV_strips_m7",11,-0.5,10.5,11,-0.5,10.5 );

TH1F *h_m0_Um = new TH1F("h_m0_Um","ClustU_strips_m0",1000, 0,10);
TH1F *h_m1_Um = new TH1F("h_m1_Um","ClustU_strips_m1",1000, 0,10);
TH1F *h_m2_Um = new TH1F("h_m2_Um","ClustU_strips_m2",1000, 0,10);
TH1F *h_m3_Um = new TH1F("h_m3_Um","ClustU_strips_m3",1000, 0,10);
TH1F *h_m4_Um = new TH1F("h_m4_Um","ClustU_strips_m4",1000, 0,10);
TH1F *h_m5_Um = new TH1F("h_m5_Um","ClustU_strips_m5",1000, 0,10);
TH1F *h_m6_Um = new TH1F("h_m6_Um","ClustU_strips_m6",1000, 0,10);
TH1F *h_m7_Um = new TH1F("h_m7_Um","ClustU_strips_m7",1000, 0,10);


TH2F *h_m0_UVm = new TH2F("h_m0_UVm","ClustU_strips_m0 vs  ClustV_strips_m0",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m1_UVm = new TH2F("h_m1_UVm","ClustU_strips_m1 vs  ClustV_strips_m1",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m2_UVm = new TH2F("h_m2_UVm","ClustU_strips_m2 vs  ClustV_strips_m2",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m3_UVm = new TH2F("h_m3_UVm","ClustU_strips_m3 vs  ClustV_strips_m3",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m4_UVm = new TH2F("h_m4_UVm","ClustU_strips_m4 vs  ClustV_strips_m4",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m5_UVm = new TH2F("h_m5_UVm","ClustU_strips_m5 vs  ClustV_strips_m5",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m6_UVm = new TH2F("h_m6_UVm","ClustU_strips_m6 vs  ClustV_strips_m6",11,-0.5,10.5,11,-0.5,10.5 );
TH2F *h_m7_UVm = new TH2F("h_m7_UVm","ClustU_strips_m7 vs  ClustV_strips_m7",11,-0.5,10.5,11,-0.5,10.5 );

TH1F *h_m0_Vm = new TH1F("h_m0_Vm","ClustV_strips_m0",1000, 0,10);
TH1F *h_m1_Vm = new TH1F("h_m1_Vm","ClustV_strips_m1",1000, 0,10);
TH1F *h_m2_Vm = new TH1F("h_m2_Vm","ClustV_strips_m2",1000, 0,10);
TH1F *h_m3_Vm = new TH1F("h_m3_Vm","ClustV_strips_m3",1000, 0,10);
TH1F *h_m4_Vm = new TH1F("h_m4_Vm","ClustV_strips_m4",1000, 0,10);
TH1F *h_m5_Vm = new TH1F("h_m5_Vm","ClustV_strips_m5",1000, 0,10);
TH1F *h_m6_Vm = new TH1F("h_m6_Vm","ClustV_strips_m6",1000, 0,10);
TH1F *h_m7_Vm = new TH1F("h_m7_Vm","ClustV_strips_m7",1000, 0,10);

TH1F *h_m0_m4_Um = new TH1F("h_m0_m4_Um","ClustU_strips_m0-m4",140,-0.3,0.3);
TH1F *h_m1_m5_Um = new TH1F("h_m1_m5_Um","ClustU_strips_m1-m5",140,-0.3,0.3);
TH1F *h_m2_m6_Um = new TH1F("h_m2_m6_Um","ClustU_strips_m2-m6",140,-0.3,0.3);
TH1F *h_m3_m7_Um = new TH1F("h_m3_m7_Um","ClustU_strips_m3-m7",140,-0.3,0.3);
TH1F *h_m0_m4_Vm = new TH1F("h_m0_m4_Vm","ClustV_strips_m0-m4",140,-0.3,0.3);
TH1F *h_m1_m5_Vm = new TH1F("h_m1_m5_Vm","ClustV_strips_m1-m5",140,-0.3,0.3);
TH1F *h_m2_m6_Vm = new TH1F("h_m2_m6_Vm","ClustV_strips_m2-m6",140,-0.3,0.3);
TH1F *h_m3_m7_Vm = new TH1F("h_m3_m7_Vm","ClustV_strips_m3-m7",140,-0.3,0.3);


//making 2D histogram for PR GEMS
TH2F *hPRhodoVsPRGEMHits_m0m4_U = new TH2F("hPRhodoVsPRGEMHits_m0m4_U","HodoPR_adc_time vs ClustU_strips_m0m4",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m1m5_U= new TH2F("hPRhodoVsPRGEMHits_m1m5_U","HodoPR_adc_time vs  ClustU_strips_m1m5",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m2m6_U= new TH2F("hPRhodoVsPRGEMHits_m2m6_U","HodoPR_adc_time vs  ClustU_strips_m2m6",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m3m7_U= new TH2F("hPRhodoVsPRGEMHits_m3m7_U","HodoPR_adc_time vs  ClustU_strips_m3m7",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m0m4_V = new TH2F("hPRhodoVsPRGEMHits_m0m4_V","HodoPR_adc_time vs ClustV_strips_m0m4",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m1m5_V= new TH2F("hPRhodoVsPRGEMHits_m1m5_V","HodoPR_adc_time vs  ClustV_strips_m1m5",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m2m6_V= new TH2F("hPRhodoVsPRGEMHits_m2m6_V","HodoPR_adc_time vs  ClustV_strips_m2m6",300,-50,550,12,-12,12);
TH2F *hPRhodoVsPRGEMHits_m3m7_V= new TH2F("hPRhodoVsPRGEMHits_m3m7_V","HodoPR_adc_time vs  ClustV_strips_m3m7",300,-50,550,12,-12,12);

//making 2D histogram for PR GEMS
TH2F *hPRhodoVsPRGEMHits_m0_U = new TH2F("hPRhodoVsPRGEMHits_m0_U","HodoPR_adc_time vs ClustU_strips_m0",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m1_U= new TH2F("hPRhodoVsPRGEMHits_m1_U","HodoPR_adc_time vs  ClustU_strips_m1",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m2_U= new TH2F("hPRhodoVsPRGEMHits_m2_U","HodoPR_adc_time vs  ClustU_strips_m2",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m3_U= new TH2F("hPRhodoVsPRGEMHits_m3_U","HodoPR_adc_time vs  ClustU_strips_m3",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m4_U = new TH2F("hPRhodoVsPRGEMHits_m4_U","HodoPR_adc_time vs ClustU_strips_m4",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m5_U= new TH2F("hPRhodoVsPRGEMHits_m5_U","HodoPR_adc_time vs  ClustU_strips_m5",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m6_U= new TH2F("hPRhodoVsPRGEMHits_m6_U","HodoPR_adc_time vs  ClustU_strips_m6",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m7_U= new TH2F("hPRhodoVsPRGEMHits_m7_U","HodoPR_adc_time vs  ClustU_strips_m7",300,-50,550,7,-1,13);

TH2F *hPRhodoVsPRGEMHits_m0_V = new TH2F("hPRhodoVsPRGEMHits_m0_V","HodoPR_adc_time vs ClustV_strips_m0",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m1_V= new TH2F("hPRhodoVsPRGEMHits_m1_V","HodoPR_adc_time vs  ClustV_strips_m1",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m2_V= new TH2F("hPRhodoVsPRGEMHits_m2_V","HodoPR_adc_time vs  ClustV_strips_m2",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m3_V= new TH2F("hPRhodoVsPRGEMHits_m3_V","HodoPR_adc_time vs  ClustV_strips_m3",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m4_V = new TH2F("hPRhodoVsPRGEMHits_m4_V","HodoPR_adc_time vs ClustV_strips_m4",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m5_V= new TH2F("hPRhodoVsPRGEMHits_m5_V","HodoPR_adc_time vs  ClustV_strips_m5",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m6_V= new TH2F("hPRhodoVsPRGEMHits_m6_V","HodoPR_adc_time vs  ClustV_strips_m6",300,-50,550,7,-1,13);
TH2F *hPRhodoVsPRGEMHits_m7_V= new TH2F("hPRhodoVsPRGEMHits_m7_V","HodoPR_adc_time vs  ClustV_strips_m7",300,-50,550,7,-1,13);

//2D plots with respect to hodoPR_adc_elemID
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U = new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U","HodoPR_adc_adcelemID vs ClustU_strips_m0m4",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U","HodoPR_adc_adcelemID vs  ClustU_strips_m1m5",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U","HodoPR_adc_adcelemID vs ClustU_strips_m2m6", 30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U","HodoPR_adc_adcelemID vs  ClustU_strips_m3m7",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V = new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V","HodoPR_adc_adcelemID vs ClustV_strips_m0m4",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V","HodoPR_adc_adcelemID  vs ClustV_strips_m1m5",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V","HodoPR_adc_adcelemID vs  ClustV_strips_m2m6",30,-5,55,12,-12,12);
TH2F *hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V= new TH2F("hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V","HodoPR_adc_adcelemID vs  ClustV_strips_m3m7",30,-5,55,12,-12,12);



Long64_t nentries = T->GetEntries();
for (Long64_t i = 0; i<nentries ; i++) {
   T->GetEntry(i);

// for Position
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_adc; j++){
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_adc; n++){
for (int j1=0; j1< Ndata_sbs_hodoPR_adc_a; j1++){
for (int j3=0; j3< Ndata_sbs_hodoPR_adc_adcelemID; j3++){
if (sbs_gemPR_m0_clust_clustu_strips[j]>0 && sbs_gemPR_m4_clust_clustu_strips[n]>0){
if (sbs_hodoPR_adc_a_time[j1]>0 && sbs_hodoPR_adc_adcelemID[j3]>0 ){
double strips_Diffrence_m0m4_U =sbs_gemPR_m0_clust_clustu_strips[j] - sbs_gemPR_m4_clust_clustu_strips[n];
     h_m0m4_Um->Fill(sbs_gemPR_m0_clust_clustu_strips[j],sbs_gemPR_m4_clust_clustu_strips[n]);
     h_m0_Um->Fill(sbs_gemPR_m0_clust_clustu_strips[j]);
     h_m4_Um->Fill(sbs_gemPR_m4_clust_clustu_strips[n]);
     h_m0_m4_Um->Fill(strips_Diffrence_m0m4_U);
hPRhodoVsPRGEMHits_m0m4_U->Fill( sbs_hodoPR_adc_a_time[j1],strips_Diffrence_m0m4_U);
hPRhodoVsPRGEMHits_m0_U->Fill( sbs_hodoPR_adc_a_time[j1],sbs_gemPR_m0_clust_clustu_strips[j]);
hPRhodoVsPRGEMHits_m4_U->Fill( sbs_hodoPR_adc_a_time[j1],sbs_gemPR_m4_clust_clustu_strips[n]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_U->Fill(sbs_hodoPR_adc_adcelemID[j3], strips_Diffrence_m0m4_U);
}}}}}}
for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
for (int k1=0; k1< Ndata_sbs_hodoPR_adc_a; k1++){
for (int k3=0; k3< Ndata_sbs_hodoPR_adc_adcelemID; k3++){
if (sbs_gemPR_m1_clust_clustu_strips[k]>0 && sbs_gemPR_m5_clust_clustu_strips[o]>0 && sbs_hodoPR_adc_a_time[k1]>0 && sbs_hodoPR_adc_adcelemID[k3]>0) {
double strips_Diffrence_m1m5_U =sbs_gemPR_m1_clust_clustu_strips[k] - sbs_gemPR_m5_clust_clustu_strips[o];
    h_m1m5_Um->Fill(sbs_gemPR_m1_clust_clustu_strips[k],sbs_gemPR_m5_clust_clustu_strips[o]);
    h_m1_Um->Fill(sbs_gemPR_m1_clust_clustu_strips[k]);
    h_m5_Um->Fill(sbs_gemPR_m5_clust_clustu_strips[o]);
    h_m1_m5_Um->Fill(strips_Diffrence_m1m5_U);
hPRhodoVsPRGEMHits_m1m5_U->Fill(sbs_hodoPR_adc_a_time[k1], strips_Diffrence_m1m5_U);
hPRhodoVsPRGEMHits_m1_U->Fill( sbs_hodoPR_adc_a_time[k1],sbs_gemPR_m1_clust_clustu_strips[k]);
hPRhodoVsPRGEMHits_m5_U->Fill( sbs_hodoPR_adc_a_time[k1],sbs_gemPR_m5_clust_clustu_strips[o]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_U->Fill(sbs_hodoPR_adc_adcelemID[k3], strips_Diffrence_m1m5_U);
}}}}}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
for (int l1=0; l1<Ndata_sbs_hodoPR_adc_a; l1++){
for (int l3=0; l3< Ndata_sbs_hodoPR_adc_adcelemID; l3++){
if (sbs_gemPR_m2_clust_clustu_strips[l]>0 && sbs_gemPR_m6_clust_clustu_strips[p]>0 && sbs_hodoPR_adc_a_time[l1]>0 && sbs_hodoPR_adc_adcelemID[l3]>0){
double strips_Diffrence_m2m6_U =sbs_gemPR_m2_clust_clustu_strips[l] - sbs_gemPR_m6_clust_clustu_strips[p];
  h_m2m6_Um->Fill(sbs_gemPR_m2_clust_clustu_strips[l],sbs_gemPR_m6_clust_clustu_strips[p]);
  h_m2_Um->Fill(sbs_gemPR_m2_clust_clustu_strips[l]);
  h_m6_Um->Fill(sbs_gemPR_m6_clust_clustu_strips[p]);
  h_m2_m6_Um->Fill(strips_Diffrence_m2m6_U);
hPRhodoVsPRGEMHits_m2m6_U->Fill(sbs_hodoPR_adc_a_time[l1], strips_Diffrence_m2m6_U);
hPRhodoVsPRGEMHits_m2_U->Fill( sbs_hodoPR_adc_a_time[l1],sbs_gemPR_m2_clust_clustu_strips[l]);
hPRhodoVsPRGEMHits_m6_U->Fill( sbs_hodoPR_adc_a_time[l1],sbs_gemPR_m6_clust_clustu_strips[p]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_U->Fill(sbs_hodoPR_adc_adcelemID[l3], strips_Diffrence_m2m6_U);
}}}}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
for (int m1=0; m1< Ndata_sbs_hodoPR_adc_a; m1++){
for (int m3=0; m3< Ndata_sbs_hodoPR_adc_adcelemID; m3++){
if (sbs_gemPR_m3_clust_clustu_strips[m]>0 && sbs_gemPR_m7_clust_clustu_strips[q]>0 && sbs_hodoPR_adc_a_time[m1]>0 && sbs_hodoPR_adc_adcelemID[m3]>0){
double strips_Diffrence_m3m7_U =sbs_gemPR_m3_clust_clustu_strips[m] - sbs_gemPR_m7_clust_clustu_strips[q];
   h_m3m7_Um->Fill(sbs_gemPR_m3_clust_clustu_strips[m],sbs_gemPR_m7_clust_clustu_strips[q]);
   h_m3_Um->Fill(sbs_gemPR_m3_clust_clustu_strips[m]);
   h_m7_Um->Fill(sbs_gemPR_m7_clust_clustu_strips[q]);
   h_m3_m7_Um->Fill(strips_Diffrence_m3m7_U);
hPRhodoVsPRGEMHits_m3m7_U->Fill(sbs_hodoPR_adc_a_time[m1], strips_Diffrence_m3m7_U);
hPRhodoVsPRGEMHits_m3_U->Fill( sbs_hodoPR_adc_a_time[m1],sbs_gemPR_m3_clust_clustu_strips[m]);
hPRhodoVsPRGEMHits_m7_U->Fill( sbs_hodoPR_adc_a_time[m1],sbs_gemPR_m7_clust_clustu_strips[q]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_U->Fill(sbs_hodoPR_adc_adcelemID[m3], strips_Diffrence_m3m7_U);
}}}}}
//Condition apply for V strips
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
for (int j2=0; j2< Ndata_sbs_hodoPR_adc_a; j2++){
for (int j3=0; j3< Ndata_sbs_hodoPR_adc_adcelemID; j3++){
if (sbs_gemPR_m0_clust_clustv_strips[j1]>0 && sbs_gemPR_m4_clust_clustv_strips[n1]>0){
if (sbs_hodoPR_adc_a_time[j2]>0 && sbs_hodoPR_adc_adcelemID[j3]>0){
double strips_Diffrence_m0m4_V =sbs_gemPR_m0_clust_clustv_strips[j1] - sbs_gemPR_m4_clust_clustv_strips[n1];
   h_m0m4_Vm->Fill(sbs_gemPR_m0_clust_clustv_strips[j1],sbs_gemPR_m4_clust_clustv_strips[n1]);
   h_m0_Vm->Fill(sbs_gemPR_m0_clust_clustv_strips[j1]);
   h_m4_Vm->Fill(sbs_gemPR_m4_clust_clustv_strips[n1]);
   h_m0_m4_Vm->Fill(strips_Diffrence_m0m4_V);
hPRhodoVsPRGEMHits_m0m4_V->Fill(sbs_hodoPR_adc_a_time[j2],strips_Diffrence_m0m4_V);
hPRhodoVsPRGEMHits_m0_V->Fill(sbs_hodoPR_adc_a_time[j2],sbs_gemPR_m0_clust_clustv_strips[j1]);
hPRhodoVsPRGEMHits_m4_V->Fill(sbs_hodoPR_adc_a_time[j2],sbs_gemPR_m4_clust_clustv_strips[n1]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m0m4_V->Fill(sbs_hodoPR_adc_adcelemID[j3], strips_Diffrence_m0m4_V);
}}}}}}

for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
for (int k2=0; k2< Ndata_sbs_hodoPR_adc_a; k2++){
for (int k3=0; k3< Ndata_sbs_hodoPR_adc_adcelemID; k3++){
if (sbs_gemPR_m1_clust_clustv_strips[k1]>0 && sbs_gemPR_m5_clust_clustv_strips[o1]>0 && sbs_hodoPR_adc_a_time[k2]>0 &&sbs_hodoPR_adc_adcelemID[k3]>0) {
double strips_Diffrence_m1m5_V =sbs_gemPR_m1_clust_clustv_strips[k1] - sbs_gemPR_m5_clust_clustv_strips[o1];
    h_m1m5_Vm->Fill(sbs_gemPR_m1_clust_clustv_strips[k1],sbs_gemPR_m5_clust_clustv_strips[o1]);
    h_m1_Vm->Fill(sbs_gemPR_m1_clust_clustv_strips[k1]);
    h_m5_Vm->Fill(sbs_gemPR_m5_clust_clustv_strips[o1]);
    h_m1_m5_Vm->Fill(strips_Diffrence_m1m5_V);
hPRhodoVsPRGEMHits_m1m5_V->Fill(sbs_hodoPR_adc_a_time[k2], strips_Diffrence_m1m5_V);
hPRhodoVsPRGEMHits_m1_V->Fill(sbs_hodoPR_adc_a_time[k2],sbs_gemPR_m1_clust_clustv_strips[k1]);
hPRhodoVsPRGEMHits_m5_V->Fill(sbs_hodoPR_adc_a_time[k2],sbs_gemPR_m5_clust_clustv_strips[o1]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m1m5_V->Fill(sbs_hodoPR_adc_adcelemID[k3], strips_Diffrence_m1m5_V);
}}}}}
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
for (int l2=0; l2<Ndata_sbs_hodoPR_adc_a; l2++){
for (int l3=0; l3< Ndata_sbs_hodoPR_adc_adcelemID; l3++){
if (sbs_gemPR_m2_clust_clustv_strips[l1]>0 && sbs_gemPR_m6_clust_clustv_strips[p1]>0 && sbs_hodoPR_adc_a_time[l2]>0 &&sbs_hodoPR_adc_adcelemID[l3]>0){
double strips_Diffrence_m2m6_V =sbs_gemPR_m2_clust_clustv_strips[l1] - sbs_gemPR_m6_clust_clustv_strips[p1];
    h_m2m6_Vm->Fill(sbs_gemPR_m2_clust_clustv_strips[l1],sbs_gemPR_m6_clust_clustv_strips[p1]);
    h_m2_Vm->Fill(sbs_gemPR_m2_clust_clustv_strips[l1]);
    h_m6_Vm->Fill(sbs_gemPR_m6_clust_clustv_strips[p1]);
    h_m2_m6_Vm->Fill(strips_Diffrence_m2m6_V);
hPRhodoVsPRGEMHits_m2m6_V->Fill(sbs_hodoPR_adc_a_time[l2], strips_Diffrence_m2m6_V);
hPRhodoVsPRGEMHits_m2_V->Fill(sbs_hodoPR_adc_a_time[l2],sbs_gemPR_m2_clust_clustv_strips[l1]);
hPRhodoVsPRGEMHits_m6_V->Fill(sbs_hodoPR_adc_a_time[l2],sbs_gemPR_m6_clust_clustv_strips[p1]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m2m6_V->Fill(sbs_hodoPR_adc_adcelemID[l3], strips_Diffrence_m2m6_V);
}}}}}
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
for (int m2=0; m2< Ndata_sbs_hodoPR_adc_a; m2++){
for (int m3=0; m3< Ndata_sbs_hodoPR_adc_adcelemID; m3++){
if (sbs_gemPR_m3_clust_clustv_strips[m1]>0 && sbs_gemPR_m7_clust_clustv_strips[q1]>0 && sbs_hodoPR_adc_a_time[m2]>0 && sbs_hodoPR_adc_adcelemID[m3]>0){
double strips_Diffrence_m3m7_V =sbs_gemPR_m3_clust_clustv_strips[m1] - sbs_gemPR_m7_clust_clustv_strips[q1];
    h_m3m7_Vm->Fill(sbs_gemPR_m3_clust_clustv_strips[m1],sbs_gemPR_m7_clust_clustv_strips[q1]);
    h_m3_Vm->Fill(sbs_gemPR_m3_clust_clustv_strips[m1]);
    h_m7_Vm->Fill(sbs_gemPR_m7_clust_clustv_strips[q1]);
    h_m3_m7_Vm->Fill(strips_Diffrence_m3m7_V);
hPRhodoVsPRGEMHits_m3m7_V->Fill(sbs_hodoPR_adc_a_time[m2], strips_Diffrence_m3m7_V);
hPRhodoVsPRGEMHits_m3_V->Fill(sbs_hodoPR_adc_a_time[m2],sbs_gemPR_m3_clust_clustv_strips[m1]);
hPRhodoVsPRGEMHits_m7_V->Fill(sbs_hodoPR_adc_a_time[m2],sbs_gemPR_m7_clust_clustv_strips[q1]);
hPRhodo_adc_adcelemID_Vs_PRGEMHits_time_m3m7_V->Fill(sbs_hodoPR_adc_adcelemID[m3], strips_Diffrence_m3m7_V);
}}}}}


//UVm per module
for (int j=0; j< Ndata_sbs_gemPR_m0_clust_clustu_adc; j++){
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_adc; j1++){
h_m0_UVm->Fill(sbs_gemPR_m0_clust_clustu_strips[j],sbs_gemPR_m0_clust_clustv_strips[j1]);
}}
for (int k=0; k< Ndata_sbs_gemPR_m1_clust_clustu_adc; k++){
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_adc; k1++){
h_m1_UVm->Fill(sbs_gemPR_m1_clust_clustu_strips[k],sbs_gemPR_m1_clust_clustv_strips[k1]);
 }}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_adc; l++){
for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_adc; l1++){
h_m2_UVm->Fill(sbs_gemPR_m2_clust_clustu_strips[l],sbs_gemPR_m2_clust_clustv_strips[l1]);
}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_adc; m++){
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustv_adc; m1++){
h_m3_UVm->Fill(sbs_gemPR_m3_clust_clustu_strips[m],sbs_gemPR_m3_clust_clustv_strips[m1]);
}}
for (int n=0; n< Ndata_sbs_gemPR_m4_clust_clustu_adc; n++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_adc; n1++){
h_m4_UVm->Fill(sbs_gemPR_m4_clust_clustu_strips[n],sbs_gemPR_m4_clust_clustv_strips[n1]);
}}
for (int o=0; o< Ndata_sbs_gemPR_m5_clust_clustu_adc; o++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_adc; o1++){
h_m5_UVm->Fill(sbs_gemPR_m5_clust_clustu_strips[o],sbs_gemPR_m5_clust_clustv_strips[o1]);
}}
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_adc; p++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_adc; p1++){
h_m6_UVm->Fill(sbs_gemPR_m6_clust_clustu_strips[p],sbs_gemPR_m6_clust_clustv_strips[p1]);
}}
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_adc; q++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_adc; q1++){
h_m7_UVm->Fill(sbs_gemPR_m7_clust_clustu_strips[q],sbs_gemPR_m7_clust_clustv_strips[q1]);
}}
}

TCanvas *Cm = new TCanvas("Cm", "GEMPR_ClustU and V_Strips", 1200, 600);
Cm->Divide(4,2);
Cm->cd(1);
h_m0m4_Um->SetXTitle("GEMPR_m0 Clustu_strips");
h_m0m4_Um->SetYTitle("GEMPR_m4 Clustu_strips");
h_m0m4_Um->Draw("COLZ");
Cm->cd(2);
h_m1m5_Um->SetXTitle("GEMPR_m1 Clustu_strips");
h_m1m5_Um->SetYTitle("GEMPR_m5 Clustu_strips");
h_m1m5_Um->Draw("COLZ");
Cm->cd(3);
h_m2m6_Um->SetXTitle("GEMPR_m2 Clustu_strips");
h_m2m6_Um->SetYTitle("GEMPR_m6 Clustu_strips");
h_m2m6_Um->Draw("COLZ");
Cm->cd(4);
h_m3m7_Um->SetXTitle("GEMPR_m3 Clustu_strips");
h_m3m7_Um->SetYTitle("GEMPR_m7 Clustu_strips");
h_m3m7_Um->Draw("COLZ");
Cm->cd(5);
h_m0m4_Vm->SetXTitle("GEMPR_m0 Clustv_strips");
h_m0m4_Vm->SetYTitle("GEMPR_m4 Clustv_strips");
h_m0m4_Vm->Draw("COLZ");
Cm->cd(6);
h_m1m5_Vm->SetXTitle("GEMPR_m1 Clustv_strips");
h_m1m5_Vm->SetYTitle("GEMPR_m5 Clustv_strips");
h_m1m5_Vm->Draw("COLZ");
Cm->cd(7);
h_m2m6_Vm->SetXTitle("GEMPR_m2 Clustv_strips");
h_m2m6_Vm->SetYTitle("GEMPR_m6 Clustv_strips");
h_m2m6_Vm->Draw("COLZ");
Cm->cd(8);
h_m3m7_Vm->SetXTitle("GEMPR_m3 Clustv_strips");
h_m3m7_Vm->SetYTitle("GEMPR_m7 Clustv_strips");
h_m3m7_Vm->Draw("COLZ");

TCanvas *CCc = new TCanvas("CCc", "GEMPR_ClustUV_strips", 1200, 600);
CCc->Divide(4,2);
CCc->cd(1);
h_m0_UVm->SetXTitle("GEMPR_m0 Clustu_strips");
h_m0_UVm->SetYTitle("GEMPR_m0 Clustv_strips");
h_m0_UVm->Draw("COLZ");
CCc->cd(2);
h_m1_UVm->SetXTitle("GEMPR_m1 Clustu_strips");
h_m1_UVm->SetYTitle("GEMPR_m1 Clustv_strips");
h_m1_UVm->Draw("COLZ");
CCc->cd(3);
h_m2_UVm->SetXTitle("GEMPR_m2 Clustu_strips");
h_m2_UVm->SetYTitle("GEMPR_m2 Clustv_strips");
h_m2_UVm->Draw("COLZ");
CCc->cd(4);
h_m3_UVm->SetXTitle("GEMPR_m3 Clustu_strips");
h_m3_UVm->SetYTitle("GEMPR_m3 Clustv_strips");
h_m3_UVm->Draw("COLZ");
CCc->cd(5);
h_m4_UVm->SetXTitle("GEMPR_m4 Clustu_strips");
h_m4_UVm->SetYTitle("GEMPR_m4 Clustv_strips");
h_m4_UVm->Draw("COLZ");
CCc->cd(6);
h_m5_UVm->SetXTitle("GEMPR_m5 Clustu_strips");
h_m5_UVm->SetYTitle("GEMPR_m5 Clustv_strips");
h_m5_UVm->Draw("COLZ");
CCc->cd(7);
h_m6_UVm->SetXTitle("GEMPR_m6 Clustu_strips");
h_m6_UVm->SetYTitle("GEMPR_m6 Clustv_strips");
h_m6_UVm->Draw("COLZ");
CCc->cd(8);
h_m7_UVm->SetXTitle("GEMPR_m7 Clustu_strips");
h_m7_UVm->SetYTitle("GEMPR_m7 Clustv_strips");
h_m7_UVm->Draw("COLZ");

TCanvas *CCCC = new TCanvas("CCCC", " GEMPR_L1_Um vs Vm_strips ", 1200, 600);
CCCC->Divide(4,2);
CCCC->cd(1);
h_m0_Um->SetXTitle("GEMPR_m0 Clustu_strips");
h_m0_Um->Draw("HIST");
CCCC->cd(2);
h_m1_Um->SetXTitle("GEMPR_m1 Clustu_strips");
h_m1_Um->Draw("HIST");
CCCC->cd(3);
h_m2_Um->SetXTitle("GEMPR_m2 Clustu_strips");
h_m2_Um->Draw("HIST");
CCCC->cd(4);
h_m3_Um->SetXTitle("GEMPR_m3 Clustu_strips");
h_m3_Um->Draw("HIST");
CCCC->cd(5);
h_m0_Vm->SetXTitle("GEMPR_m0 Clustv_strips");
h_m0_Vm->Draw("HIST");
CCCC->cd(6);
h_m1_Vm->SetXTitle("GEMPR_m1 Clustv_strips");
h_m1_Vm->Draw("HIST");
CCCC->cd(7);
h_m2_Vm->SetXTitle("GEMPR_m2 Clustv_strips");
h_m2_Vm->Draw("HIST");
CCCC->cd(8);
h_m3_Vm->SetXTitle("GEMPR_m3 Clustv_strips");
h_m3_Vm->Draw("HIST");

TCanvas *ccC = new TCanvas("ccC", " GEMPR_L2_Um vs Vm_strips", 1200, 600);
ccC->Divide(4,2);
ccC->cd(1);
h_m4_Um->SetXTitle("GEMPR_m4 ClustU_strips");
h_m4_Um->Draw("HIST");
ccC->cd(2);
h_m5_Um->SetXTitle("GEMPR_m5 ClustU_strips");
h_m5_Um->Draw("HIST");
ccC->cd(3);
h_m6_Um->SetXTitle("GEMPR_m6 ClustU_strips");
h_m6_Um->Draw("HIST");
ccC->cd(4);
h_m7_Um->SetXTitle("GEMPR_m7 ClustU_strips");
h_m7_Um->Draw("HIST");
ccC->cd(5);
h_m4_Vm->SetXTitle("GEMPR_m4 ClustV_strips");
h_m4_Vm->Draw("HIST");
ccC->cd(6);
h_m5_Vm->SetXTitle("GEMPR_m5 ClustV_strips");
h_m5_Vm->Draw("HIST");
ccC->cd(7);
h_m6_Vm->SetXTitle("GEMPR_m6 ClustV_strips");
h_m6_Vm->Draw("HIST");
ccC->cd(8);
h_m7_Vm->SetXTitle("GEMPR_m7 ClustV_strips");
h_m7_Vm->Draw("HIST");

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

TCanvas* Cccanvas = new TCanvas("Cccanvas", "PRhodo Time vs PRGEM_U Hits", 800, 600);
Cccanvas->Divide(4,2);
Cccanvas->cd(1);
hPRhodoVsPRGEMHits_m0_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m0_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m0_U->SetYTitle("Hits on module_m0_U");
Cccanvas->cd(2);
hPRhodoVsPRGEMHits_m1_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m1_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m1_U->SetYTitle("Hits on module_m1_U");
Cccanvas->cd(3);
hPRhodoVsPRGEMHits_m2_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m2_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m2_U->SetYTitle("Hits on module_m2_U");
Cccanvas->cd(4);
hPRhodoVsPRGEMHits_m3_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m3_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m3_U->SetYTitle("Hits on module_m3_U");
Cccanvas->cd(5);
hPRhodoVsPRGEMHits_m4_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m4_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m4_U->SetYTitle("Hits on module_m4_U");
Cccanvas->cd(6);
hPRhodoVsPRGEMHits_m5_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m5_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m5_U->SetYTitle("Hits on module_m5_U");
Cccanvas->cd(7);
hPRhodoVsPRGEMHits_m6_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m6_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m6_U->SetYTitle("Hits on module_m6_U");
Cccanvas->cd(8);
hPRhodoVsPRGEMHits_m7_U->Draw("COLZ");
hPRhodoVsPRGEMHits_m7_U->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m7_U->SetYTitle("Hits on module_m7_U");

TCanvas* CCccanvas = new TCanvas("CCccanvas", "PRhodo Time vs PRGEM_V Hits", 800, 600);
CCccanvas->Divide(4,2);
CCccanvas->cd(1);
hPRhodoVsPRGEMHits_m0_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m0_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m0_V->SetYTitle("Hits on module_m0_V");
CCccanvas->cd(2);
hPRhodoVsPRGEMHits_m1_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m1_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m1_V->SetYTitle("Hits on module_m1m5_V");
CCccanvas->cd(3);
hPRhodoVsPRGEMHits_m2_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m2_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m2_V->SetYTitle("Hits on module_m2m6_V");
CCccanvas->cd(4);
hPRhodoVsPRGEMHits_m3_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m3_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m3_V->SetYTitle("Hits on module_m3_V");
CCccanvas->cd(5);
hPRhodoVsPRGEMHits_m4_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m4_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m4_V->SetYTitle("Hits on module_m4_V");
CCccanvas->cd(6);
hPRhodoVsPRGEMHits_m5_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m5_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m5_V->SetYTitle("Hits on module_m5_V");
CCccanvas->cd(7);
hPRhodoVsPRGEMHits_m6_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m6_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m6_V->SetYTitle("Hits on module_m6_V");
CCccanvas->cd(8);
hPRhodoVsPRGEMHits_m7_V->Draw("COLZ");
hPRhodoVsPRGEMHits_m7_V->SetXTitle("PRhodo_adc_Time");
hPRhodoVsPRGEMHits_m7_V->SetYTitle("Hits on module_m7_V");

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

TCanvas *cCCC = new TCanvas("cCCC", " GEMPR_ClustU_strips_Difference and V_strips_Differenece", 1200, 600);
cCCC->Divide(4,2);
cCCC->cd(1);
h_m0_m4_Um->SetXTitle("GEMPR_m0-m4 Clustu_strips_Difference");
h_m0_m4_Um->Draw("COLZ");
cCCC->cd(2);
h_m1_m5_Um->SetXTitle("GEMPR_m1-m5 Clustu_strips_Difference");
h_m1_m5_Um->Draw("COLZ");
cCCC->cd(3);
h_m2_m6_Um->SetXTitle("GEMPR_m2-m6 Clustu_strips_Difference");
h_m2_m6_Um->Draw("COLZ");
cCCC->cd(4);
h_m3_m7_Um->SetXTitle("GEMPR_m3-m7 Clustu_strips_Difference");
h_m3_m7_Um->Draw("COLZ");
cCCC->cd(5);
h_m0_m4_Vm->SetXTitle("GEMPR_m0-m4 Clustv_strips_Difference");
h_m0_m4_Vm->Draw("COLZ");
cCCC->cd(6);
h_m1_m5_Vm->SetXTitle("GEMPR_m1-m5 Clustv_strips_Difference");
h_m1_m5_Vm->Draw("COLZ");
cCCC->cd(7);
h_m2_m6_Vm->SetXTitle("GEMPR_m2-m6 Clustv_strips_Difference");
h_m2_m6_Vm->Draw("COLZ");
cCCC->cd(8);
h_m3_m7_Vm->SetXTitle("GEMPR_m3-m7 Clustv_strips_Difference");
h_m3_m7_Vm->Draw("COLZ");

}
