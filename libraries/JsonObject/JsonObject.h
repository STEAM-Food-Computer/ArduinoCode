//
//  JsonObject.h
//  
//
//  Created by Madalitso Mchaina on 2018-03-06.
//

#ifndef JsonObject_h
#define JsonObject_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif
#include <string.h>

class JsonObject {
    String jsonString;
    
public:
    JsonObject();
    template<typename K, typename V>
    JsonObject(K, V);
    template<typename K>
    JsonObject(K, JsonObject j);
    template<typename K, typename V>
    void add(K, V);
    template<typename K>
    void add(K, JsonObject j);
    String stringify();
    
};

JsonObject::JsonObject() {
    jsonString = "{";
}
template<typename K, typename V>
JsonObject::JsonObject(K key, V value) {
    String s = "";
    s.concat("{");
    s.concat(String(key));
    s.concat(":");
    s.concat(String(value));
    s.concat("}");
    jsonString = s;
    
}
template<typename K>
JsonObject::JsonObject(K key, JsonObject j) {
    String s = "";
    s.concat("{");
    s.concat(String(key));
    s.concat(":");
    s.concat(j.stringify());
    s.concat("}");
}

template<typename K>
void JsonObject::add(K key, JsonObject j) {
    if (jsonString.length() == 1) {}
    else {
        jsonString.setCharAt(jsonString.length() - 1, ',');
    }
    jsonString.concat(String(key));
    jsonString.concat(":");
    jsonString.concat(j.stringify());
    jsonString.concat("}");
}
template<typename K, typename V>
void JsonObject::add(K key, V value) {
    if (jsonString.length() == 1) {}
    else {
        jsonString.setCharAt(jsonString.length() - 1, ',');
    }
    jsonString.concat(String(key));
    jsonString.concat(":");
    jsonString.concat(String(value));
    jsonString.concat("}");
}
String JsonObject::stringify() {
    return jsonString;
}

#endif



