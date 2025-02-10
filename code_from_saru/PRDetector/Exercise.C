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

void Exercise() {

 TChain *T = new TChain("T");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_1.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_2.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_3.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_4.root");
 T->Add("/adaqfs/home/a-onl/Saru/Test/Practice/GEMs_PR/ROOTfiles/genrp_replay_test_1123_100000_events_5.root");

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

//for Layer1
double sbs_gemPR_m1_clust_clustu_time[10000];
double sbs_gemPR_m1_clust_clustv_time[10000];
double sbs_gemPR_m0_clust_clustu_time[10000];
double sbs_gemPR_m0_clust_clustv_time[10000];
double sbs_gemPR_m2_clust_clustu_time[10000];
double sbs_gemPR_m2_clust_clustv_time[10000];
double sbs_gemPR_m3_clust_clustu_time[10000];
double sbs_gemPR_m3_clust_clustv_time[10000];

double sbs_gemPR_m0_hit_hitTavg[10000];
double sbs_gemPR_m1_hit_hitTavg[10000];
double sbs_gemPR_m2_hit_hitTavg[10000];
double sbs_gemPR_m3_hit_hitTavg[10000];
double sbs_gemPR_m4_hit_hitTavg[10000];
double sbs_gemPR_m5_hit_hitTavg[10000];
double sbs_gemPR_m6_hit_hitTavg[10000];
double sbs_gemPR_m7_hit_hitTavg[10000];

int Ndata_sbs_gemPR_m0_hit_hitTavg;
int Ndata_sbs_gemPR_m1_hit_hitTavg;
int Ndata_sbs_gemPR_m2_hit_hitTavg;
int Ndata_sbs_gemPR_m3_hit_hitTavg;
int Ndata_sbs_gemPR_m4_hit_hitTavg;
int Ndata_sbs_gemPR_m5_hit_hitTavg;
int Ndata_sbs_gemPR_m6_hit_hitTavg;
int Ndata_sbs_gemPR_m7_hit_hitTavg;

double sbs_gemPR_m0_hit_hitTdiff[10000];
double sbs_gemPR_m1_hit_hitTdiff[10000];
double sbs_gemPR_m2_hit_hitTdiff[10000];
double sbs_gemPR_m3_hit_hitTdiff[10000];
double sbs_gemPR_m4_hit_hitTdiff[10000];
double sbs_gemPR_m5_hit_hitTdiff[10000];
double sbs_gemPR_m6_hit_hitTdiff[10000];
double sbs_gemPR_m7_hit_hitTdiff[10000];

int Ndata_sbs_gemPR_m0_hit_hitTdiff;
int Ndata_sbs_gemPR_m1_hit_hitTdiff;
int Ndata_sbs_gemPR_m2_hit_hitTdiff;
int Ndata_sbs_gemPR_m3_hit_hitTdiff;
int Ndata_sbs_gemPR_m4_hit_hitTdiff;
int Ndata_sbs_gemPR_m5_hit_hitTdiff;
int Ndata_sbs_gemPR_m6_hit_hitTdiff;
int Ndata_sbs_gemPR_m7_hit_hitTdiff;

double sbs_gemPR_m0_hit_hitxg[10000];
double sbs_gemPR_m1_hit_hitxg[10000];
double sbs_gemPR_m2_hit_hitxg[10000];
double sbs_gemPR_m3_hit_hitxg[10000];
double sbs_gemPR_m4_hit_hitxg[10000];
double sbs_gemPR_m5_hit_hitxg[10000];
double sbs_gemPR_m6_hit_hitxg[10000];
double sbs_gemPR_m7_hit_hitxg[10000];
double sbs_gemPR_m0_hit_hityg[10000];
double sbs_gemPR_m1_hit_hityg[10000];
double sbs_gemPR_m2_hit_hityg[10000];
double sbs_gemPR_m3_hit_hityg[10000];
double sbs_gemPR_m4_hit_hityg[10000];
double sbs_gemPR_m5_hit_hityg[10000];
double sbs_gemPR_m6_hit_hityg[10000];
double sbs_gemPR_m7_hit_hityg[10000];

int Ndata_sbs_gemPR_m0_hit_hitxg;
int Ndata_sbs_gemPR_m1_hit_hitxg;
int Ndata_sbs_gemPR_m2_hit_hitxg;
int Ndata_sbs_gemPR_m3_hit_hitxg;
int Ndata_sbs_gemPR_m4_hit_hitxg;
int Ndata_sbs_gemPR_m5_hit_hitxg;
int Ndata_sbs_gemPR_m6_hit_hitxg;
int Ndata_sbs_gemPR_m7_hit_hitxg;
int Ndata_sbs_gemPR_m0_hit_hityg;
int Ndata_sbs_gemPR_m1_hit_hityg;
int Ndata_sbs_gemPR_m2_hit_hityg;
int Ndata_sbs_gemPR_m3_hit_hityg;
int Ndata_sbs_gemPR_m4_hit_hityg;
int Ndata_sbs_gemPR_m5_hit_hityg;
int Ndata_sbs_gemPR_m6_hit_hityg;
int Ndata_sbs_gemPR_m7_hit_hityg;

int Ndata_sbs_gemPR_m1_clust_clustu_time;
int Ndata_sbs_gemPR_m1_clust_clustv_time;
int Ndata_sbs_gemPR_m0_clust_clustu_time;
int Ndata_sbs_gemPR_m0_clust_clustv_time;
int Ndata_sbs_gemPR_m2_clust_clustu_time;
int Ndata_sbs_gemPR_m2_clust_clustv_time;
int Ndata_sbs_gemPR_m3_clust_clustu_time;
int Ndata_sbs_gemPR_m3_clust_clustv_time;

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

T->SetBranchAddress("sbs.gemPR.m0.hit.hitTavg", &sbs_gemPR_m0_hit_hitTavg);
T->SetBranchAddress("sbs.gemPR.m1.hit.hitTavg", &sbs_gemPR_m1_hit_hitTavg);
T->SetBranchAddress("sbs.gemPR.m3.hit.hitTavg", &sbs_gemPR_m2_hit_hitTavg);
T->SetBranchAddress("sbs.gemPR.m3.hit.hitTavg", &sbs_gemPR_m3_hit_hitTavg);
T->SetBranchAddress("sbs.gemPR.m4.hit.hitTavg", &sbs_gemPR_m4_hit_hitTavg);
T->SetBranchAddress("sbs.gemPR.m5.hit.hitTavg", &sbs_gemPR_m5_hit_hitTavg);
T->SetBranchAddress("sbs.gemPR.m6.hit.hitTavg", &sbs_gemPR_m6_hit_hitTavg);
T->SetBranchAddress("sbs.gemPR.m7.hit.hitTavg", &sbs_gemPR_m7_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.hit.hitTavg", &Ndata_sbs_gemPR_m0_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.hit.hitTavg", &Ndata_sbs_gemPR_m1_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.hit.hitTavg", &Ndata_sbs_gemPR_m2_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.hit.hitTavg", &Ndata_sbs_gemPR_m3_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.hit.hitTavg", &Ndata_sbs_gemPR_m4_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.hit.hitTavg", &Ndata_sbs_gemPR_m5_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.hit.hitTavg", &Ndata_sbs_gemPR_m6_hit_hitTavg);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.hit.hitTavg", &Ndata_sbs_gemPR_m7_hit_hitTavg);

T->SetBranchAddress("sbs.gemPR.m0.hit.hitTdiff", &sbs_gemPR_m0_hit_hitTdiff);
T->SetBranchAddress("sbs.gemPR.m1.hit.hitTdiff", &sbs_gemPR_m1_hit_hitTdiff);
T->SetBranchAddress("sbs.gemPR.m3.hit.hitTdiff", &sbs_gemPR_m2_hit_hitTdiff);
T->SetBranchAddress("sbs.gemPR.m3.hit.hitTdiff", &sbs_gemPR_m3_hit_hitTdiff);
T->SetBranchAddress("sbs.gemPR.m4.hit.hitTdiff", &sbs_gemPR_m4_hit_hitTdiff);
T->SetBranchAddress("sbs.gemPR.m5.hit.hitTdiff", &sbs_gemPR_m5_hit_hitTdiff);
T->SetBranchAddress("sbs.gemPR.m6.hit.hitTdiff", &sbs_gemPR_m6_hit_hitTdiff);
T->SetBranchAddress("sbs.gemPR.m7.hit.hitTdiff", &sbs_gemPR_m7_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.hit.hitTdiff", &Ndata_sbs_gemPR_m0_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.hit.hitTdiff", &Ndata_sbs_gemPR_m1_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.hit.hitTdiff", &Ndata_sbs_gemPR_m2_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.hit.hitTdiff", &Ndata_sbs_gemPR_m3_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.hit.hitTdiff", &Ndata_sbs_gemPR_m4_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.hit.hitTdiff", &Ndata_sbs_gemPR_m5_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.hit.hitTdiff", &Ndata_sbs_gemPR_m6_hit_hitTdiff);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.hit.hitTdiff", &Ndata_sbs_gemPR_m7_hit_hitTdiff);

T->SetBranchAddress("sbs.gemPR.m0.hit.hitxg", &sbs_gemPR_m0_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m1.hit.hitxg", &sbs_gemPR_m1_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m2.hit.hitxg", &sbs_gemPR_m2_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m3.hit.hitxg", &sbs_gemPR_m3_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m4.hit.hitxg", &sbs_gemPR_m4_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m5.hit.hitxg", &sbs_gemPR_m5_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m6.hit.hitxg", &sbs_gemPR_m6_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m7.hit.hitxg", &sbs_gemPR_m7_hit_hitxg);
T->SetBranchAddress("sbs.gemPR.m0.hit.hityg", &sbs_gemPR_m0_hit_hityg);
T->SetBranchAddress("sbs.gemPR.m1.hit.hityg", &sbs_gemPR_m1_hit_hityg);
T->SetBranchAddress("sbs.gemPR.m2.hit.hityg", &sbs_gemPR_m2_hit_hityg);
T->SetBranchAddress("sbs.gemPR.m3.hit.hityg", &sbs_gemPR_m3_hit_hityg);
T->SetBranchAddress("sbs.gemPR.m4.hit.hityg", &sbs_gemPR_m4_hit_hityg);
T->SetBranchAddress("sbs.gemPR.m5.hit.hityg", &sbs_gemPR_m5_hit_hityg);
T->SetBranchAddress("sbs.gemPR.m6.hit.hityg", &sbs_gemPR_m6_hit_hityg);
T->SetBranchAddress("sbs.gemPR.m7.hit.hityg", &sbs_gemPR_m7_hit_hityg);

T->SetBranchAddress("Ndata.sbs.gemPR.m0.hit.hitxg", &Ndata_sbs_gemPR_m0_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.hit.hitxg", &Ndata_sbs_gemPR_m1_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.hit.hitxg", &Ndata_sbs_gemPR_m2_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.hit.hitxg", &Ndata_sbs_gemPR_m3_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.hit.hitxg", &Ndata_sbs_gemPR_m4_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.hit.hitxg", &Ndata_sbs_gemPR_m5_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.hit.hitxg", &Ndata_sbs_gemPR_m6_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.hit.hitxg", &Ndata_sbs_gemPR_m7_hit_hitxg);
T->SetBranchAddress("Ndata.sbs.gemPR.m0.hit.hityg", &Ndata_sbs_gemPR_m0_hit_hityg);
T->SetBranchAddress("Ndata.sbs.gemPR.m1.hit.hityg", &Ndata_sbs_gemPR_m1_hit_hityg);
T->SetBranchAddress("Ndata.sbs.gemPR.m2.hit.hityg", &Ndata_sbs_gemPR_m2_hit_hityg);
T->SetBranchAddress("Ndata.sbs.gemPR.m3.hit.hityg", &Ndata_sbs_gemPR_m3_hit_hityg);
T->SetBranchAddress("Ndata.sbs.gemPR.m4.hit.hityg", &Ndata_sbs_gemPR_m4_hit_hityg);
T->SetBranchAddress("Ndata.sbs.gemPR.m5.hit.hityg", &Ndata_sbs_gemPR_m5_hit_hityg);
T->SetBranchAddress("Ndata.sbs.gemPR.m6.hit.hityg", &Ndata_sbs_gemPR_m6_hit_hityg);
T->SetBranchAddress("Ndata.sbs.gemPR.m7.hit.hityg", &Ndata_sbs_gemPR_m7_hit_hityg);


//2D Histogram plots for timing information od HodoPR_adc_time vs PRgems_clust_time
//making 2D histogram for PR GEMS
TH2F *h_m0m4_U = new TH2F("h_m0m4_U","HitTavg_4 vs HodoPR_a_time", 160,-80,80,500,-10,500);
TH2F *h_m1m5_U = new TH2F("h_m1m5_U","HitTavg_5 vs HodoPR_a_time",160,-80,80,500,-10,500);
TH2F *h_m2m6_U = new TH2F("h_m2m6_U","ClustU_time_m2 vs  ClustU_time_m6",100,-2,150,100,0,140);
TH2F *h_m3m7_U = new TH2F("h_m3m7_U","ClustU_time_m3 vs  ClustU_time_m7",100,-2,150,100,0,140);
TH2F *h_m0m4_V = new TH2F("h_m0m4_V","ClustV_time_m0 vs  ClustV_time_m4",100,-2,150,100,0,140);
TH2F *h_m1m5_V = new TH2F("h_m1m5_V","ClustV_time_m1 vs  ClustV_time_m5",100,-2,150,100,0,140);
TH2F *h_m2m6_V = new TH2F("h_m2m6_V","ClustV_time_m2 vs  ClustV_time_m6",100,-2,150,100,0,140);
TH2F *h_m3m7_V = new TH2F("h_m3m7_V","ClustV_time_m3 vs  ClustV_time_m7",100,-2,150,100,0,140);

TH1F *h_m0_m4_U = new TH1F("h_m0_m4_U","ClustU_time_m0-m4",140,-140,140 );
TH1F *h_m1_m5_U = new TH1F("h_m1_m5_U","ClustU_time_m1-m5",140,-140,140);
TH1F *h_m2_m6_U = new TH1F("h_m2_m6_U","ClustU_time_m2-m6",140,-140,140);
TH1F *h_m3_m7_U = new TH1F("h_m3_m7_U","ClustU_time_m3-m7",140,-140,140);
TH1F *h_m0_m4_V = new TH1F("h_m0_m4_V","ClustV_time_m0-m4",140,-140,140);
TH1F *h_m1_m5_V = new TH1F("h_m1_m5_V","ClustV_time_m1-m5",140,-140,140);
TH1F *h_m2_m6_V = new TH1F("h_m2_m6_V","ClustV_time_m2-m6",140,-140,140);
TH1F *h_m3_m7_V = new TH1F("h_m3_m7_V","ClustV_time_m3-m7",140,-140,140);

Long64_t nentries = T->GetEntries();
for (Long64_t i = 0; i<nentries ; i++) {
   T->GetEntry(i);

//cout<<"value" <<i<<'\t' << Ndata_sbs_gemPR_m0_clust_clustu_adc<<'\t'<< Ndata_sbs_gemPR_m0_clust_clustu_time<<endl;

 for (int j=0; j< Ndata_sbs_gemPR_m0_hit_hitTavg; j++){
  for (int n=0; n< Ndata_sbs_gemPR_m4_hit_hitTavg; n++){
    //double Time_Diffrence_m0m4_U =sbs_gemPR_m0_clust_clustu_time[j] - sbs_gemPR_m4_clust_clustu_time[n];
for (int j1=0; j1< Ndata_sbs_hodoPR_adc_adcelemID; j1++){
if(sbs_hodoPR_adc_adcelemID[j1] >=16 && sbs_hodoPR_adc_adcelemID[j1] <=23){
// FIll the 2D Histogram of GemPR_m4 time w.r.to m0
     h_m0m4_U->Fill(sbs_gemPR_m4_hit_hitTavg[n],sbs_hodoPR_adc_a_time[j1]);
 //    h_m0_m4_U->Fill(Time_Diffrence_m0m4_U);
}}}}


for (int k=0; k< Ndata_sbs_gemPR_m1_hit_hitTavg; k++){
for (int o=0; o< Ndata_sbs_gemPR_m5_hit_hitTavg; o++){
  // double Time_Diffrence_m1m5_U =sbs_gemPR_m1_clust_clustu_time[k] - sbs_gemPR_m5_clust_clustu_time[o];
for (int j2=0; j2< Ndata_sbs_hodoPR_adc_adcelemID; j2++){
if(sbs_hodoPR_adc_adcelemID[j2] >=10 && sbs_hodoPR_adc_adcelemID[j2] <=19){
    h_m1m5_U->Fill(sbs_gemPR_m5_hit_hitTavg[o],sbs_hodoPR_adc_a_time[j2]);
    //h_m1_m5_U->Fill(Time_Diffrence_m1m5_U);
}}}}
for (int l=0; l< Ndata_sbs_gemPR_m2_clust_clustu_time; l++){
for (int p=0; p< Ndata_sbs_gemPR_m6_clust_clustu_time; p++){
   double Time_Diffrence_m2m6_U =sbs_gemPR_m2_clust_clustu_time[l] - sbs_gemPR_m6_clust_clustu_time[p];
  h_m2m6_U->Fill(sbs_gemPR_m2_clust_clustu_time[l],sbs_gemPR_m6_clust_clustu_time[p]);
  h_m2_m6_U->Fill(Time_Diffrence_m2m6_U);
}}
for (int m=0; m< Ndata_sbs_gemPR_m3_clust_clustu_time; m++){
for (int q=0; q< Ndata_sbs_gemPR_m7_clust_clustu_time; q++){
    double Time_Diffrence_m3m7_U =sbs_gemPR_m3_clust_clustu_time[m] - sbs_gemPR_m7_clust_clustu_time[q];
   h_m3m7_U->Fill(sbs_gemPR_m3_clust_clustu_time[m],sbs_gemPR_m7_clust_clustu_time[q]);
   h_m3_m7_U->Fill(Time_Diffrence_m3m7_U);
}}
// For V Strips
for (int j1=0; j1< Ndata_sbs_gemPR_m0_clust_clustv_time; j1++){
for (int n1=0; n1< Ndata_sbs_gemPR_m4_clust_clustv_time; n1++){
   double Time_Diffrence_m0m4_V =sbs_gemPR_m0_clust_clustv_time[j1] - sbs_gemPR_m4_clust_clustv_time[n1];
   h_m0m4_V->Fill(sbs_gemPR_m0_clust_clustv_time[j1],sbs_gemPR_m4_clust_clustv_time[n1]);
   h_m0_m4_V->Fill(Time_Diffrence_m0m4_V);
  }}
for (int k1=0; k1< Ndata_sbs_gemPR_m1_clust_clustv_time; k1++){
for (int o1=0; o1< Ndata_sbs_gemPR_m5_clust_clustv_time; o1++){
   double Time_Diffrence_m1m5_U =sbs_gemPR_m1_clust_clustv_time[k1] - sbs_gemPR_m5_clust_clustv_time[o1];
    h_m1m5_V->Fill(sbs_gemPR_m1_clust_clustv_time[k1],sbs_gemPR_m5_clust_clustv_time[o1]);
    h_m1_m5_V->Fill(Time_Diffrence_m1m5_U);
}}

for (int l1=0; l1< Ndata_sbs_gemPR_m2_clust_clustv_time; l1++){
for (int p1=0; p1< Ndata_sbs_gemPR_m6_clust_clustv_time; p1++){
   double Time_Diffrence_m2m6_V =sbs_gemPR_m2_clust_clustv_time[l1] - sbs_gemPR_m6_clust_clustv_time[p1];
    h_m2m6_V->Fill(sbs_gemPR_m2_clust_clustv_time[l1],sbs_gemPR_m6_clust_clustv_time[p1]);
   h_m2_m6_V->Fill(Time_Diffrence_m2m6_V);
}}
for (int m1=0; m1< Ndata_sbs_gemPR_m3_clust_clustu_time; m1++){
for (int q1=0; q1< Ndata_sbs_gemPR_m7_clust_clustv_time; q1++){
    double Time_Diffrence_m3m7_V =sbs_gemPR_m3_clust_clustv_time[m1] - sbs_gemPR_m7_clust_clustv_time[q1];
    h_m3m7_V->Fill(sbs_gemPR_m3_clust_clustv_time[m1],sbs_gemPR_m7_clust_clustv_time[q1]);
    h_m3_m7_V->Fill(Time_Diffrence_m3m7_V);

}}}

TCanvas *C = new TCanvas("C", "GEMPR_ClustUandV_Time", 1200, 600);
C->Divide(4,2);
C->cd(1);
h_m0m4_U->SetXTitle("GEMhitTavg");
h_m0m4_U->SetYTitle("HodoPR_adc_Time");
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
/*
TCanvas *CC = new TCanvas("CC", " GEMPR_ClustU_Time_Difference and V_Time_Differenece", 1200, 600);
CC->Divide(4,2);
CC->cd(1);
h_m0_m4_U->SetXTitle("GEMPR_m0-m4 Clustu_Time_Difference");
h_m0_m4_U->Draw("HIST");
CC->cd(2);
h_m1_m5_U->SetXTitle("GEMPR_m1-m5 Clustu_Time_Difference");
h_m1_m5_U->Draw("HIST");
CC->cd(3);
h_m2_m6_U->SetXTitle("GEMPR_m2-m6 Clustu_Time_Difference");
h_m2_m6_U->Draw("HIST");
CC->cd(4);
h_m3_m7_U->SetXTitle("GEMPR_m3-m7 Clustu_Time_Difference");
h_m3_m7_U->Draw("HIST");
CC->cd(5);
h_m0_m4_V->SetXTitle("GEMPR_m0-m4 Clustv_Time_Difference");
h_m0_m4_V->Draw("HIST");
CC->cd(6);
h_m1_m5_V->SetXTitle("GEMPR_m1-m5 Clustv_Time_Difference");
h_m1_m5_V->Draw("HIST");
CC->cd(7);
h_m2_m6_V->SetXTitle("GEMPR_m2-m6 Clustv_Time_Difference");
h_m2_m6_V->Draw("HIST");
CC->cd(8);
h_m3_m7_V->SetXTitle("GEMPR_m3-m7 Clustv_Time_Difference");
h_m3_m7_V->Draw("HIST");
*/
}
