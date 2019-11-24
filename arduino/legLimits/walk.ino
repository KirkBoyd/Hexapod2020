void fwd(){
  evensDown();
  delay(waitTime);
  oddsUp();
  oddsFwd();
  evensBack();
  delay(waitTime);
  oddsDown();
  delay(waitTime);
  evensUp();
  evensFwd();
  oddsBack();
  delay(waitTime);
}
void oddsFwd(){
  SetPosition(CFR, CFRfwd);
  SetPosition(CRR, CRRfwd);
  SetPosition(CML, CMLfwd);
}
void oddsBack(){
  SetPosition(CFR, CFRback);
  SetPosition(CRR, CRRback);
  SetPosition(CML, CMLback);
}
void evensFwd(){
  SetPosition(CFL, CFLfwd);
  SetPosition(CRL, CRLfwd);
  SetPosition(CMR, CMRfwd);
}
void evensBack(){
  SetPosition(CFL, CFLback);
  SetPosition(CRL, CRLback);
  SetPosition(CMR, CMRback);
}

void oddsUp(){
  SetPosition(FFR, FFRup);
  SetPosition(TFR, TFRup);
  SetPosition(FRR, FRRup);
  SetPosition(TRR, TRRup);
  SetPosition(FML, FMLup);
  SetPosition(TML, TMLup);
}
void oddsDown(){
  SetPosition(FFR, FFRdown);
  //SetPosition(TFR, TFRdown);
  SetPosition(FRR, FRRdown);
  //SetPosition(TRR, TRRdown);
  SetPosition(FML, FMLdown);
  //SetPosition(TML, TMLdown);
}
void evensUp(){
  SetPosition(FFL, FFLup);
  SetPosition(TFL, TFLup);
  SetPosition(FRL, FRLup);
  SetPosition(TRL, TRLup);
  SetPosition(FMR, FMRup);
  SetPosition(TMR, TMRup);
}
void evensDown(){
  SetPosition(FFL, FFLdown);
  //SetPosition(TFL, TFLdown);
  SetPosition(FRL, FRLdown);
  //SetPosition(TRL, TRRdown);
  SetPosition(FMR, FMRdown);
//  //SetPosition(TMR, TMRdown);
}
