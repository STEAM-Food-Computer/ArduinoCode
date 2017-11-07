#include <HumidThermoSensor.h>

HumidThermoSensor::HumidThermoSensor(char pinNum) : pinNumber(pinNum) {}

void HumidThermoSensor::updateSensorValues() {
    int clk = sensorModule.read11(pinNumber); //I do not think it is necessary to declare this int
    temperature = sensorModule.temperature;
    humidity = sensorModule.humidity;
}

double HumidThermoSensor::getTemperature() {
    return temperature;
}

double HumidThermoSensor::getHumidity() {
    return humidity;
}