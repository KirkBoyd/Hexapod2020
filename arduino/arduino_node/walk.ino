void fwd(){
  evensDown();
  delay(waitTime);
  oddsUp();
  delay(shortWait);
  oddsFwd();
  delay(shortWait);
  evensBack();
  delay(waitTime);
  oddsDown();
  delay(waitTime);
  evensUp();
  delay(shortWait);
  evensFwd();
  delay(shortWait);
  oddsBack();
  delay(waitTime);
}
void turnL(){
  oddsDown();
    delay(waitTime);
  evensUp();
    delay(shortWait);
  evensCCW();
    delay(shortWait);
  oddsCW();
    delay(shortWait);
  evensDown();
    delay(waitTime);
  oddsUp();
    delay(shortWait);
  oddsCCW();
    delay(shortWait);
  evensCW();
    delay(shortWait);
}
void turnR(){
  oddsDown();
    delay(waitTime);
  evensUp();
    delay(shortWait);
  evensCW();
    delay(shortWait);
  oddsCCW();
    delay(shortWait);
  evensDown();
    delay(waitTime);
  oddsUp();
    delay(shortWait);
  oddsCW();
    delay(shortWait);
  evensCCW();
    delay(shortWait);
}
void oddsCW(){
  SetPosition(CFR, CFRback);
  SetPosition(CRR, CRRback);
  SetPosition(CML, CMLfwd);
}
void oddsCCW(){
  SetPosition(CFR, CFRfwd);
  SetPosition(CRR, CRRfwd);
  SetPosition(CML, CMLback);
}
void evensCW(){
  SetPosition(CMR, CMRback);
  SetPosition(CRL, CRLfwd);
  SetPosition(CFL, CFLfwd);
}
void evensCCW(){
  SetPosition(CMR, CMRfwd);
  SetPosition(CRL, CRLback);
  SetPosition(CFL, CFLback);
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
