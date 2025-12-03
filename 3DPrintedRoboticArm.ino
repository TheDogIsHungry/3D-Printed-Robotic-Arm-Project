#include <Servo.h>
static int ypos=150;
static int xpos=90;
static int zpos=280; 
static int wrpos=90;
static int wppos=90;
int gpos=90;
int comdel=0;
int movdel=10;

const int xpin=5;
const int ypin=6;
const int zpin=7;
const int wrpin=8;
const int wppin=9;
const int gpin=10;
Servo servx;
Servo servy;
Servo servz;
Servo servwr;
Servo servwp;
Servo servg;
int close=110;
int open=160;

void setup() {
  Serial.begin(9600);
 
  servx.attach(xpin);
  servy.attach(ypin);
  servz.attach(zpin);
  servwr.attach(wrpin);
  servwp.attach(wppin);
  servg.attach(gpin);

  
  //home pos

  servx.write(90);
  delay(movdel);
  servy.write(90);
  delay(movdel);
  servz.write(0);
  delay(movdel);
  servwr.write(90);
  delay(movdel);
  servwp.write(90);
  delay(movdel);
  
  grip(false);
  
  
//hey vedannt, its grady, cool code, dude. 
  

}

void loop() {



  grip(false);
  combsm(180,60,105);
  delay(movdel);
  



  delay(movdel);
  combsm(180,35,160);
  Serial.println("first move");
 
  grip(true);
  delay(movdel);
  
  combsm(90,90,150);
  Serial.println("second move");
  
  
  delay(movdel);
  combsm(0,35,150);
  
  delay(movdel);
  grip(false);

  
  Serial.println("repeat");
  delay(1000);


  
}


void grip(boolean in)
{
  if (in== true ){servg.write(close);}
  else {servg.write(open);}
}

static void combsm(int x,int y,int z)
{ 
  xpos = servx.read();
  ypos = servy.read();
  zpos = servz.read();
  wppos = servwp.read();
  wrpos = servwr.read();
  int wp = y+z +10;
  int wr = 90;
  
  while ((x != xpos)|(y != ypos)|(z != zpos)|(wr != wrpos)|(wp != wppos))
  {
    
    
    
    if(wr>wrpos){servwr.write(wrpos); wrpos++;}
    if(wr=wrpos){servwr.write(wrpos);}
    if(wr<wrpos){servwr.write(wrpos); wrpos--;}
    delay(comdel);
    if(z>zpos){servz.write(zpos); zpos++;}
    if(z==zpos){servz.write(zpos);}
    if(z<zpos){servz.write(zpos); zpos--;}
    delay(comdel);
    if(y>ypos){servy.write(ypos); ypos++;}
    if(y==ypos){servy.write(ypos);}
    if(y<ypos){servy.write(ypos); ypos--;}
    delay(comdel);
    if(x>xpos){servx.write(xpos); xpos++;}
    if(x==xpos){servx.write(xpos);}
    if(x<xpos){servx.write(xpos); xpos--;}
    delay(comdel);
    if(wp>wppos){servwp.write(wppos); wppos++;}
    if(wp==wppos){servwp.write(wppos);}
    if(wp<wppos){servwp.write(wppos); wppos--;}
    delay(comdel);
    Serial.print("x=");
    Serial.print(xpos);
    Serial.print("y=");
    Serial.print(ypos);
    Serial.print("z=");
    Serial.print(zpos);
    Serial.print("wrist=");
    Serial.print(wrpos);
    Serial.print("wp=");
    Serial.println(wppos);
    
  }
}