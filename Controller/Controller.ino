#include <WaterPump.h>
#include <GrowLight.h>
#include <Fan.h>

GrowLight g(8, 1000);
WaterPump w(9, 1000);
Fan *f[2];

void setup() {
  f[0] = new Fan(10, 2000);
  f[1] = new Fan(11, 2000);
}

void loop() {
  g.strobe();
  w.strobe();
  for(int i = 0; i < sizeof(f); i++)
    f[i]->strobe();
}
