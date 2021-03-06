#include <iostream>

#include <TMath.h>
#include <TFile.h>
#include <TGraph.h>
#include <TCanvas.h>

using namespace std;

void PseudoScalar5(void)
{
  
  double  Mdm,Mmed,width,xsection1,xsection2,qu,qd,qc,qs,qt,qb;
  double v;

  double xsection3,xsection4,xsection5,xsection6,xsection7,xsection8,xsection9,xsection10,xsection11,xsection12,xsection13,xsection14;
  double sumsqterm,sumsqterm1,ag,at,ab,ac;
	
	TCanvas *c = new TCanvas();

    TGraph *g1 = new TGraph();
 TGraph *g2 = new TGraph();
 TGraph *g3 = new TGraph();
 TGraph *g4 = new TGraph();
 
  qu = 2.3e-3;
  qd = 4.8e-3;
  qc = 1.275;
  qs = 9.5e-2;
  qt = 173.21;
  qb = 4.66;
  v = 246;
  //cout<<"Mmed"<<endl;
  //cin>>Mmed;
  //cout<<"Mdm"<<endl;
  //cin>>Mdm;
  // Mdm = 180;
  Mmed =2500 ;

  for (Mdm = 1; Mdm <= 500 ; Mdm= Mdm+1){ 
    
    width = 0;
   
     if(Mmed>2*Mdm){     width = width + ( Mmed/(8*3.14)*sqrt(1-4*Mdm*Mdm/(Mmed*Mmed)) );}
     if(Mmed>2*qu) {     width = width + ( 6*qu*qu*Mmed/(16*3.14*v*v)*sqrt(1-4*qu*qu/(Mmed*Mmed)) );}
     if(Mmed>2*qd) {     width = width + ( 6*qd*qd*Mmed/(16*3.14*v*v)*sqrt(1-4*qd*qd/(Mmed*Mmed)) );}
     if(Mmed>2*qs) {     width = width + ( 6*qs*qs*Mmed/(16*3.14*v*v)*sqrt(1-4*qs*qs/(Mmed*Mmed)) );}
     if(Mmed>2*qt) {     width = width + ( 6*qt*qt*Mmed/(16*3.14*v*v)*sqrt(1-4*qt*qt/(Mmed*Mmed)) );}
     if(Mmed>2*qb) {     width = width + ( 6*qb*qb*Mmed/(16*3.14*v*v)*sqrt(1-4*qb*qb/(Mmed*Mmed)) );}
     if(Mmed>2*qc) {     width = width + ( 6*qc*qc*Mmed/(16*3.14*v*v)*sqrt(1-4*qc*qc/(Mmed*Mmed)) );}
     if(Mmed<2*qt){ sumsqterm1 = atan(1/sqrt(4*qt*qt/(Mmed*Mmed)-1))*atan(1/sqrt(4*qt*qt/(Mmed*Mmed)-1))*atan(1/sqrt(4*qt*qt/(Mmed*Mmed)-1))*atan(1/sqrt(4*qt*qt/(Mmed*Mmed)-1))*16*qt*qt*qt*qt/Mmed/Mmed/Mmed/Mmed;
     
       width=width+(sumsqterm1*Mmed*Mmed*Mmed*0.1184*0.1184/(1+0.132*log(Mdm/91.2))/(1+0.132*log(Mdm/91.2))/32/3.14/3.14/3.14/v/v);}

     xsection1 = 0;
      
     if(Mdm>qu){xsection1 = xsection1 + (3*qu*qu*Mdm*Mdm*sqrt(1-(qu*qu)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}
     if(Mdm>qd){xsection1 = xsection1 + (3*qd*qd*Mdm*Mdm*sqrt(1-(qd*qd)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}
     if(Mdm>qc){xsection1 = xsection1 + (3*qc*qc*Mdm*Mdm*sqrt(1-(qc*qc)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}
     if(Mdm>qs){xsection1 = xsection1 + (3*qs*qs*Mdm*Mdm*sqrt(1-(qs*qs)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}
     if(Mdm>qt){xsection1 = xsection1 + (3*qt*qt*Mdm*Mdm*sqrt(1-(qt*qt)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}
     if(Mdm>qb){xsection1 = xsection1 + (3*qb*qb*Mdm*Mdm*sqrt(1-(qb*qb)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}

     if(Mdm<qt){ sumsqterm = atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*qt*qt*qt*qt*qt*qt*qt*qt/(Mdm*Mdm*Mdm*Mdm);
     
       xsection1 =xsection1+ (0.1184*0.1184*sumsqterm/(2*3.14*3.14*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed)/(1+0.132*log(Mdm/91.2))/(1+0.132*log(Mdm/91.2)));}

     
     if(Mdm>qc){xsection4 =  (3*qc*qc*Mdm*Mdm*sqrt(1-(qc*qc)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}
     if(Mdm>qt){xsection6 =  (3*qt*qt*Mdm*Mdm*sqrt(1-(qt*qt)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}
     if(Mdm>qb){xsection7 =  (3*qb*qb*Mdm*Mdm*sqrt(1-(qb*qb)/(Mdm*Mdm))/(2*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed));}

     if(Mdm<qt){ sumsqterm = atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*atan(1/sqrt(qt*qt/(Mdm*Mdm)-1))*qt*qt*qt*qt*qt*qt*qt*qt/Mdm/Mdm/Mdm/Mdm;
     
       xsection8 = (0.1184*0.1184*sumsqterm/(2*3.14*3.14*3.14*v*v)/(((Mmed*Mmed)-4*(Mdm*Mdm))*((Mmed*Mmed)-4*(Mdm*Mdm))+width*width*Mmed*Mmed)/(1+0.132*log(Mdm/91.2))/(1+0.132*log(Mdm/91.2)));}

     ac = xsection4/xsection1;
       at = xsection6/xsection1;
         ab = xsection7/xsection1;
	   ag = xsection8/xsection1;
g1->SetPoint(g1->GetN(), Mdm, ac);
g2->SetPoint(g2->GetN(), Mdm, at);
g3->SetPoint(g3->GetN(), Mdm, ab);
g4->SetPoint(g4->GetN(), Mdm, ag);

  }

g1->SetLineWidth(2);
 g2->SetLineWidth(2);
 g3->SetLineWidth(2);
 g4->SetLineWidth(2);
g2->SetTitle("Mmed = 2500 Gev");
 g2->SetLineColor(kRed);
g2->Draw("AL");
g1->Draw("L");
g3->Draw("L");
 g3->SetLineColor(kGreen);
g4->Draw("L");
 g4->SetLineColor(kBlue);

 TLegend *legend = new TLegend(0.6,0.2,0.9,0.4);
   legend->AddEntry(g1,"c","l");
   legend->AddEntry(g2,"t","l");
     legend->AddEntry(g3,"b","l");
   legend->AddEntry(g4,"g","l");
   legend->Draw();
c->Print(br.pdf);

}
