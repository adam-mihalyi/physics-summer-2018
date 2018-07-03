#include <TTree.h>
#include <TFile.h>

void PreProcess(){
  TFile* infile=new TFile("Data2Pi.root");
  TTree* intree=(TTree*)infile->Get("HSParticles");

  Int_t aTopo=0;
  intree->SetBranchAddress("Topo",&aTopo);
  
  TFile* outfile=new TFile("ppData2Pi.root","recreate");
  TTree* outtree=(TTree*) intree->CloneTree();
  
  Int_t IsTopo0=0;
  TBranch *brTopo0=outtree->Branch("IsTopo0",&IsTopo0);


  
  for(Int_t i=0;i<intree->GetEntries();i++){
    intree->GetEntry(i);
    
    IsTopo0=(aTopo==0);

    brTopo0->Fill();
  }

  outtree->Write();
  delete outfile;

  delete infile;
}
