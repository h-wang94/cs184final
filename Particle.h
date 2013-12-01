#ifndef _Particle_h_
#define _Particle_h_
#include "Vector.h"
#include "Point3D.h"

class Particle {
  public:
    Particle(void) {};
    Particle(float mass, float density, float pressure, float coeffVis, Vector velocity, Point3D position);
	//Particle(float density, float pressure, float coeffVis, Vector velocity, Point3D position);
    ~Particle(void) {};

    // getters and setters
    float getMass() const;
    float getVolume() const;
    float getPressure() const;
	float getDensity() const;
    Vector getVelocity() const;
    Point3D getPosition() const;

    void setMass(float mass);
    //void setVolume(float volume);
    void setPressure(float pressure);
    void setVelocity(Vector velocity);
    void setPosition(Point3D position);
	void setDensity(float density);

  private:
    float mass;
    //float volume;
    float density; // can be calculated from mass and volume. m/v. but we need it because it derives from m and v.
    float pressure; // is pressure given in some other way?
    Vector velocity;
    Point3D position;
	float coeffVis;

};

std::ostream& operator<<(ostream& outs, const Particle& particle);

#endif
