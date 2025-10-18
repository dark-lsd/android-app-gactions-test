// Shamelessly used Le Chat (Mistral Chat) to get code to read sensor values
//
// Created by ariyaltharun on 10/18/25.
//

#include <accelerometerSensor.hpp>
#include <logger.hpp>

/* Accelerometer Sensor Constructor */
AccelerometerSensor::AccelerometerSensor() {
    start();
}

/* Initialize the sensor */
void AccelerometerSensor::start() {
    LOGI("Initializing Sensor....");
    sensorManager = ASensorManager_getInstance();
    // Get Sensor
    sensor = ASensorManager_getDefaultSensor(sensorManager, ASENSOR_TYPE_ACCELEROMETER);
    if (sensor == nullptr) {
        LOGE("Accelerometer Sensor is not available or android is not allowing to read accelerometer");
        return;
    }
    LOGD("Sensor Name: %s", ASensor_getName(sensor));
    ALooper* looper = ALooper_prepare(ALOOPER_PREPARE_ALLOW_NON_CALLBACKS);
    sensorEventQueue = ASensorManager_createEventQueue(sensorManager, looper, ALOOPER_EVENT_INPUT,
                                                       reinterpret_cast<ALooper_callbackFunc>(sensorEventCallback), this);
    // Enable the sensor
    ASensorEventQueue_enableSensor(sensorEventQueue, sensor);
    // Set Event Rate
    ASensorEventQueue_setEventRate(sensorEventQueue, sensor, 100);
}

/* Callback function */
void AccelerometerSensor::sensorEventCallback(int fd, int events, void *data) {
    auto *accelSensor = static_cast<AccelerometerSensor*>(data);
    ASensorEvent event;
    if (ASensorEventQueue_getEvents(accelSensor->sensorEventQueue, &event, 1) > 0) {
        accelSensor->sensorValues = { event.acceleration.x, event.acceleration.y, event.acceleration.z };
    }
}

/* Get Accelerometer Sensor Values */
Vector3 AccelerometerSensor::getSensorValues() {
    LOGD("Accelerometer Sensor Values: x=%f, y=%f, z=%f", sensorValues.x, sensorValues.y, sensorValues.z);
    return sensorValues;
}

/* Stop Sensor Reading */
void AccelerometerSensor::stop() {
    LOGI("Deinitializing sensor");
    if (sensorEventQueue) {
        ASensorEventQueue_disableSensor(sensorEventQueue, sensor);
        ASensorManager_destroyEventQueue(sensorManager, sensorEventQueue);
        sensorEventQueue = nullptr;
    }
}

/* Accelerometer Sensor Destructor */
AccelerometerSensor::~AccelerometerSensor() {
    stop();
}
