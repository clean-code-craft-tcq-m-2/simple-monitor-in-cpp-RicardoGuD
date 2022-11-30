#include <assert.h>
#include "rangeCheck.h"

int main() {
  //temperature value test
  assert(batteryIsOk(-1, 20, 0.0) == false);
  assert(batteryIsOk(0, 20, 0.0) == true);
  assert(batteryIsOk(1, 20, 0.0) == true);
  assert(batteryIsOk(44, 20, 0.0) == true);
  assert(batteryIsOk(45, 20, 0.0) == true);
  assert(batteryIsOk(46, 20, 0.0) == false);
  //state of charge test
  assert(batteryIsOk(0, 19, 0) == false);
  assert(batteryIsOk(0, 20, 0) == true);
  assert(batteryIsOk(0, 21, 0) == true);
  assert(batteryIsOk(0, 79, 0) == true);
  assert(batteryIsOk(0, 80, 0) == true);
  assert(batteryIsOk(0, 81, 0) == false);
  //state of charge test
  assert(batteryIsOk(0, 20, -.5) == false);
  assert(batteryIsOk(0, 20, 0) == true);
  assert(batteryIsOk(0, 20, .1) == true);
  assert(batteryIsOk(0, 20, .7) == true);
  assert(batteryIsOk(0, 20, .8) == true);
  assert(batteryIsOk(0, 20, .9) == false);
}
