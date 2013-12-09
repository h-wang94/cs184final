#ifndef _ParticleSystem_h_
#define _ParticleSystem_h_
#include <vector>
#include <iostream>
#include "Particle.h"
#include "SpatialGrid.h"

class ParticleSystem {
  public:
    ParticleSystem();
	  ParticleSystem(Vector grav);

    void initialize(float timestep);
	  void update(float timestep);

    void addParticle(Particle& p);
    Particle* getParticle(const unsigned int i);
    std::vector<Particle> getParticles();
    float colorFunction(Particle& p);

  private:
    Vector grav;
    float h;
    float hSq;
    std::vector<Particle> particles;

    bool debug;
	SpatialGrid grid;
	int numRowBoxes;

	  void setDensities();
	  void computeForces();
    void computePressure();
    Vector gravityForce(Particle& p);
    Vector pressureForce(Particle& p, unsigned const int& i);
    Vector viscosityForce(Particle& p, unsigned const int& i);
    Vector tensionForce(Particle& p, unsigned const int& i);
    Vector surfaceNormal(Particle& p, unsigned const int& i);
    float curvature(Particle& p, unsigned const int& i);

    float defaultKernel(Vector r);
    Vector gradientKernel(Vector r);
    float laplacianKernel(Vector r);
    Vector pressGradientKernel(Vector r);
    float viscLaplacianKernel(Vector r);

    void initializeLeapFrog(const float& dt);
    void leapFrog(const float& dt);

    void checkBoundary(Point3D* position, Vector* velocity, Vector* velocityHalf);
    void bouncebackVelocity(Vector* velocity, Vector normal);

};

#endif
