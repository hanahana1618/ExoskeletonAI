#ifndef COMMON_HPP
#define COMMON_HPP

#include <fstream>
#include <list>

#include <gene.hpp>

#define NUM_INPUTS  9
#define NUM_OUTPUTS 6
#define MAX_THREADS 5

static int innovation_number;

enum gyro {gyroX = 0, gyroY, gyroZ};   /**<Enumerated list for the x,y, and z positions for the gyro. */
enum type {input = 0, hidden, output}; /**<Enumerated list for the different kinds of nodes.*/ 

static std::list<Gene *> unique_genes;

#endif