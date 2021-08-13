#define BUTTON1_PIN  7  // 按鈕1的接腳
#define BUTTON2_PIN  8  // 按鈕2的接腳 
#define BUTTON3_PIN  2 
#define BUTTON4_PIN  4 

#define  buzzer 3   // buzzer的接腳

#define Do  523 // Do頻率
#define Re  587 // Re頻率
#define Mi  659
#define Fa  698
/*#define Mi  659
#define Fa  698
#define So  784
#define La  880
#define Si  988*/

int buttonState1 = 0;   // 按鈕1的狀態
int buttonState2 = 0;   // 按鈕2的狀態
int buttonState3 = 0;
int buttonState4 = 0;
#include <LedControl.h>
#define DIN 12
#define CLK 11
#define CS 10
LedControl LC = LedControl(DIN,CLK,CS,1);
void Update(int Map[8][8])
  {
    for(int i=0; i<8; i++)
    {
      for(int j=0; j<8; j++)
      {
        LC.setLed(0,j,i,Map[i][j]);
      }
    }
  }
int Doled[8][8]={{0,0,0,0,0,0,1,1}, 
                 {0,0,0,0,0,1,0,1},
                 {0,0,0,0,1,0,0,1},
                 {0,0,0,0,1,0,0,1},
                 {0,0,0,0,1,0,0,1},
                 {1,1,1,0,1,0,0,1},
                 {1,0,1,0,0,1,0,1},
                 {1,1,1,0,0,0,1,1}};
                 
int Reled[8][8]={{0,0,0,0,1,1,1,1}, 
                 {0,0,0,0,1,0,0,1},
                 {0,0,0,0,1,0,0,1},
                 {1,1,1,0,1,1,1,1},
                 {1,0,1,0,0,0,1,1},
                 {1,1,1,0,0,1,0,1},
                 {0,0,1,0,1,0,0,1},
                 {1,1,1,1,0,0,0,1}};  
     
int music[8][8]={{0,0,1,0,0,0,0,1}, 
                 {0,0,1,1,0,0,1,1},
                 {1,0,1,1,0,0,1,1},
                 {0,0,1,0,1,1,0,1},
                 {1,0,1,0,0,0,0,1},
                 {1,0,1,0,0,0,0,1},
                 {1,0,1,0,0,0,0,1},
                 {1,0,1,0,0,0,0,1}}; 

int letgo[8][8]={{0,0,0,0,1,1,1,1}, 
                 {0,0,0,0,0,0,0,1},
                 {0,0,0,0,0,0,0,1},
                 {0,0,0,0,1,1,1,1},
                 {0,0,0,1,0,0,0,1},
                 {0,0,1,0,1,0,0,1},
                 {0,1,1,0,1,0,0,1},
                 {1,0,0,1,0,0,0,1}}; 
                                  
void setup() {
  pinMode(buzzer,OUTPUT);   //設定buzzer的PIN腳
  pinMode(BUTTON1_PIN,INPUT); //設定按鈕1的接腳
  pinMode(BUTTON2_PIN,INPUT); //設定按鈕2的接腳
  pinMode(BUTTON3_PIN,INPUT);
  pinMode(BUTTON4_PIN,INPUT);
  pinMode(DIN,OUTPUT);
  pinMode(CS,OUTPUT);
  pinMode(CLK,OUTPUT);
  LC.shutdown(0,false);
  LC.setIntensity(0,8);
  LC.clearDisplay(0);
}

void loop() {
  buttonState1 = digitalRead(BUTTON1_PIN); //讀取按鍵1的狀態
  buttonState2 = digitalRead(BUTTON2_PIN); //讀取按鍵2的狀態
  buttonState3 = digitalRead(BUTTON3_PIN);
  buttonState4 = digitalRead(BUTTON4_PIN);
  
  if(buttonState1 == HIGH){          //如果按鍵1按了
    tone(buzzer,523); //發出Do音
    Update(Doled);
  }
  else if(buttonState2 == HIGH){     //如果按鍵2按了
    tone(buzzer,587); //發出Re音
    Update(Reled);
  }
  else if(buttonState3 == HIGH){     
    tone(buzzer,659); 
    Update(music);
  }
   else if(buttonState4 == HIGH){     
   tone(buzzer,698); 
   Update(letgo);
  }
  else{                           //如果按鍵是未按下
    noTone(buzzer); //不發聲
    LC.clearDisplay(0);
  }    
}

