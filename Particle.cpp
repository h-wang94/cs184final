#include <iostream>
#include "Particle.h"

Particle::Particle(float mass, float density, float pressure, float coeffVis, Vector velocity, Point3D position) {
  this->mass = mass;
  //this->volume = volume; //a volume refers to a group of particles not a single particle
  this->pressure = pressure;
  this->velocity = velocity;
  this->position = position;
  this->density = density;//density is dependent on the amount of particles relative to this particle
}


float Particle::getMass() const {
  return this->mass;
}

float Particle::getVolume() const {
  return (this->mass)/(this->density);
}

float Particle::getDensity() const {
  return this->density;
}

float Particle::getPressure() const {
  return this->pressure;
}

Vector Particle::getVelocity() const {
  return this->velocity;
}

Point3D Particle::getPosition() const {
  return this->position;
}

void Particle::setMass(float mass) {
  this->mass = mass;
}

/*void Particle::setVolume(float volume) {
  this->volume = volume;
}*/

void Particle::setDensity(float density) {
  this->density = density;
}

void Particle::setPressure(float pressure) {
  this->pressure = pressure;
}

void Particle::setVelocity(Vector velocity) {
  this->velocity = velocity;
}

void Particle::setPosition(Point3D position) {
  this->position = position;
}

std::ostream& operator <<(ostream& outs, const Particle& particle) {
  outs << "//==================================================//" << endl
       << "// Mass: " << particle.getMass() << endl
       << "// Volume: " << particle.getVolume() << endl
       << "// Pressure: " << particle.getPressure() << endl
       << "// Velocity: " << particle.getVelocity() << endl
       << "// Position: " << particle.getPosition() << endl
       << "//==================================================//" << endl;
  return outs;
}
