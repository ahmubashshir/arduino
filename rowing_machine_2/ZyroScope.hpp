#ifndef __ZyroScope_H__
#define __ZyroScope_H__
class Zyro
{
  private:
    byte pin;
  public:
   virtual void begin(byte Pin)
   {
       return nullptr;
   }
   virtual float readX()
   {
       return nullptr;
   }
   virtual float readY()
   {
       return nullptr
   }
   virtual float readZ()
   {
       return nullptr
   }
};

#endif
