#ifndef TIME_H
#define TIME_H

class Time 
{
public:
  Time( int = 0, int = 0 , int = 0);

  void setTime(int , int, int);

  inline void setHour( int );

  void setMinute( int );

  void setSecond( int s )
  {
    second = (s >= 0 && s < 60) ? s : 0;
  }

  inline int getHour() {return hour;}
  inline int getMinute() {return minute;}
  inline int getSecond() {return second;}

  void printUniversal();
  void printStandard();

  void tick();

private:
  int hour;
  int minute;
  int second;
};

#endif