#ifndef COMMON_HPP
#define COMMON_HPP

#include <fstream>

#define NUM_INPUTS  9
#define NUM_OUTPUTS 6
#define MAX_THREADS 5

static int global_innovation_id = 0; // this shit needs to be in the network.
					// every network need to have their own global
					// innovation id, shits wrong.

enum gyro {gyroX = 0, 
            gyroY, gyroZ};   /**<Enumerated list for 
                             the x,y, and z positions for the gyro. */
enum type {input = 0, 
            hidden, output}; /**<Enumerated list for 
                             the different kinds of nodes.*/ 

#endif