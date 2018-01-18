#define X_MAX_PIN           2
#define Y_MAX_PIN          15
#define Z_MAX_PIN          19
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40
int button1;
int button2;
int button3;
int a;
int i = 0;
int krokix;
int krokiy;
int krokiz;
int nowadata;
char movem[20];
char bf2[20];

void setup() {
  // put your setup code here, to run once:

  pinMode(X_MAX_PIN, INPUT);
  digitalWrite(X_MAX_PIN , HIGH);
  pinMode(Y_MAX_PIN, INPUT);
  digitalWrite(Y_MAX_PIN, HIGH);
  pinMode(Z_MAX_PIN, INPUT);
  digitalWrite(Z_MAX_PIN, HIGH);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_CS_PIN, OUTPUT);
  digitalWrite(X_CS_PIN, HIGH);
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_CS_PIN, OUTPUT);
  digitalWrite(Y_CS_PIN, HIGH);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_CS_PIN, OUTPUT);
  digitalWrite(Z_CS_PIN, HIGH);
  pinMode(Z_STEP_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1 = digitalRead(X_MAX_PIN );

  button2 = digitalRead(Y_MAX_PIN );

  button3 = digitalRead(Z_MAX_PIN );

  while(Serial.available())
    {
      nowadata = Serial.read();
      if(nowadata != '\n')
      {
        movem[i++] = nowadata;
      }
      else
      {
        i = 0;
        sscanf(movem,"x %d y %d z %d",&krokix, &krokiy, &krokiz);
        memset(movem, 0, sizeof(movem));
        sprintf(bf2, "%d %d %d",krokix, krokiy, krokiz);
        Serial.print(bf2);
      }
    
      

  if(krokix < 0)
  {
    digitalWrite(X_DIR_PIN, HIGH);
    krokix = abs(krokix);
  }
  else
  {
    digitalWrite(X_DIR_PIN, LOW);
    }

  if(krokiy < 0)
  {
    digitalWrite(Y_DIR_PIN, HIGH);
    krokiy = abs(krokiy);
  }
  else
  {
    digitalWrite(Y_DIR_PIN, LOW);
    }

  if(krokiz < 0)
  {
    digitalWrite(Z_DIR_PIN, HIGH);
    krokiz = abs(krokiz);
  }
    else
  {
    digitalWrite(Z_DIR_PIN, LOW);
    }

 while(krokix>0 || krokiy>0 || krokiz>0)
 {
  if(button1 == 0 && krokix>0)
    {
      digitalWrite(X_STEP_PIN, HIGH);
      krokix--;
    }
    
  if(button2 == 0 && krokiy>0)
    {
      digitalWrite(Y_STEP_PIN, HIGH);
      krokiy--;
    }

  if(button3 == 0 && krokiz>0)
    {
      digitalWrite(Z_STEP_PIN, HIGH);
      krokiz--;
    }
  delayMicroseconds(500);
  if(krokix>0)
    digitalWrite(X_STEP_PIN, LOW);
  if(krokiy>0)
    digitalWrite(Y_STEP_PIN, LOW);
  if(krokiz>0)
    digitalWrite(Z_STEP_PIN, LOW);
  delayMicroseconds(500);
 }
Serial.print('k');
    }
}
