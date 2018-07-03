#include <TTree.h>
#include <TFile.h>

void PreProcess() {

  TFile* infile=new TFile("Data2Pi.root");
  TTree* intree=(TTree*)infile->Get("HSParticles");

  Int_t aTopo=0;
  intree->SetBranchAddress("Topo",&aTopo);

  TFile* outfile=new TFile("ppData2Pi.root","recreate");
  TTree* outtree=(TTree*) intree->CloneTree();

  Float_t IsTopo0=0;
  Float_t IsTopo1=0;
  Float_t IsTopo2=0;
  Float_t IsTopo3=0;

  TBranch *brTopo0=outtree->Branch("IsTopo0",&IsTopo0);
  TBranch *brTopo1=outtree->Branch("IsTopo1",&IsTopo1);
  TBranch *brTopo2=outtree->Branch("IsTopo2",&IsTopo2);
  TBranch *brTopo3=outtree->Branch("IsTopo3",&IsTopo3);

  for(Int_t i=0;i<intree->GetEntries();i++){
    intree->GetEntry(i);

    IsTopo0=(aTopo==0);
    IsTopo1=(aTopo==1);
    IsTopo2=(aTopo==2);
    IsTopo3=(aTopo==3);

    brTopo0->Fill();
    brTopo1->Fill();
    brTopo2->Fill();
    brTopo3->Fill();
  }

  outtree->Write();
  delete outfile;

  delete infile;
}


