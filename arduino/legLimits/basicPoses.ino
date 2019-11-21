void femUp(){
  SetPosition(FFR,FFRup);
  SetPosition(FMR,FMRup);
  SetPosition(FRR,FRRup);
  SetPosition(FRL,FRLup);
  SetPosition(FML,FMLup);
  SetPosition(FFL,FFLup);
}
void femDown(){
  SetPosition(FFR,FFRdown);
  SetPosition(FMR,FMRdown);
  SetPosition(FRR,FRRdown);
  SetPosition(FRL,FRLdown);
  SetPosition(FML,FMLdown);
  SetPosition(FFL,FFLdown);
}
void toesUp(){  //bring all toes up
  SetPosition(TFR,TFRup);
  SetPosition(TMR,TMRup);
  SetPosition(TRR,TRRup);
  SetPosition(TRL,TRLup);
  SetPosition(TML,TMLup);
  SetPosition(TFL,TFLup);
}
void toesDown(){  //bring all toes down
  SetPosition(TFR,TFRdown);
  SetPosition(TMR,TMRdown);
  SetPosition(TRR,TRRdown);
  SetPosition(TRL,TRLdown);
  SetPosition(TML,TMLdown);
  SetPosition(TFL,TFLdown);
}
void coxCtr(){  //center coxa joints
  SetPosition(CFR,CFRdef);
  SetPosition(CMR,CMRdef);
  SetPosition(CRR,CRRdef);
  SetPosition(CRL,CRLdef);
  SetPosition(CML,CMLdef);
  SetPosition(CFL,CFLdef);
}
void relaxAll(){  //disables torque in every joint
  Relax(CFR);
  Relax(CMR);
  Relax(CRR);
  Relax(CRL);
  Relax(CML);
  Relax(CFL);
  Relax(TFR);
  Relax(TMR);
  Relax(TRR);
  Relax(TRL);
  Relax(TML);
  Relax(TFL);
  Relax(FFR);
  Relax(FMR);
  Relax(FRR);
  Relax(FRL);
  Relax(FML);
  Relax(FFL);
}
void stand(){
  coxCtr();
  toesUp();
  femDown();
}
