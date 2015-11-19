#ifndef __EIKONAL_H__
#define __EIKONAL_H__

#include <cstring>
#include <time.h>
#include "TriMesh.h"
#include "tetmesh.h"
#include "tetgen.h"
#include "meshFIM2d_eikonal.h"
#include "meshFIM3dEikonal.h"

/** The class that represents all of the available options for Eikonal */
class Eikonal {
public:
  Eikonal(bool isTriMesh,
    std::string fname = "../src/test/test_data/sphere_266verts.ply",
    bool verbose = false);
  virtual ~Eikonal();
  //accessor functions to the results.
  std::vector < float >& getFinalResult();
  std::vector < float >& getResultAtIteration(size_t i);
  size_t numIterations();
  void writeVTK();
  /**
  * Creates the mesh, partitions the mesh, and runs the algorithm.
  *
  * @data The set of options for the Eikonal algorithm.
  *       The defaults are used if nothing is provided.
  */
  void solveEikonal();
  /**
  * This function uses the provided analytical solutions to
  * visualize the algorithm's error after each iteration.
  *
  * @param solution The vector of expected solutions.
  */
  void printErrorGraph(std::vector<float> solution);
  //2D data
  bool verbose_;
  std::string filename_;
  std::vector<int> seedPointList_;
  int maxBlocks_;
  int maxVertsPerBlock_;
  float stopDistance_;
  bool isStructured_;
  int speedType_; // ONE (1), CURVATURE (2), NOISE (3)
  int squareLength_, squareWidth_, squareDepth_;
  int squareBlockLength_, squareBlockWidth_, squareBlockDepth_;
  int maxIterations_;
  TriMesh * triMesh_;
  TetMesh * tetMesh_;
  std::vector < std::vector <float> > iteration_values_;
  meshFIM2dEikonal *FIMPtr2d_;
  meshFIM3dEikonal *FIMPtr3d_;
  bool isTriMesh_;
};

#endif
