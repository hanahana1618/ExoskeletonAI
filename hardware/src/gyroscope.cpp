#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "LSM9DS1_Types.h"
#include "LSM9DS1.h"

/*int main(int argc, char *argv[]) {
    LSM9DS1 imu(IMU_MODE_I2C, 0x6a, 0x1c);
    imu.begin();
    if (!imu.begin()) {
        fprintf(stderr, "Failed to communicate with LSM9DS1.\n");
        exit(EXIT_FAILURE);
    }
    imu.calibrate();

    for (;;) {
        while (!imu.gyroAvailable()) ;
        imu.readGyro();
        while(!imu.accelAvailable()) ;
        imu.readAccel();
        while(!imu.magAvailable()) ;
        imu.readMag();

        printf("Gyro: %f, %f, %f [deg/s]\n", imu.calcGyro(imu.gx), imu.calcGyro(imu.gy), imu.calcGyro(imu.gz));
        printf("Accel: %f, %f, %f [Gs]\n", imu.calcAccel(imu.ax), imu.calcAccel(imu.ay), imu.calcAccel(imu.az));
        printf("Mag: %f, %f, %f [gauss]\n", imu.calcMag(imu.mx), imu.calcMag(imu.my), imu.calcMag(imu.mz));
        sleep(1.0);
    }

    exit(EXIT_SUCCESS);
}*/

void gyroInit(float *gyro, float *accel, float *mag);

int main (int argc, char **argv){
	float a[3] = {0}, b[3] = {0}, c[3] = {0};
	gyroInit(a,b,c);
	printf("%f, %f, %f [deg/s]\n", a[0], a[1], a[2]);

exit(0);
}

void gyroInit(float *gyro, float *accel, float *mag){
	float *loc = NULL;

	LSM9DS1 imu(IMU_MODE_I2C, 0x6a, 0x1c);
	imu.begin();
	if (!imu.begin()){
		fprintf(stderr, "Failed to communicate with LSM9DS1.\n");
		exit(EXIT_FAILURE);
	}
	imu.calibrate();

	for(;;){
		while (!imu.gyroAvailable());
		imu.readGyro();
		while (!imu.accelAvailable());
		imu.readAccel();
		while (!imu.magAvailable());
		imu.readMag();

		*gyro = imu.calcGyro(imu.gx);
		*loc = *gyro + 1;
		*loc = imu.calcGyro(imu.gy);
		*loc = *gyro + 2;
		*loc = imu.calcGyro(imu.gz);
		sleep(1.0);
	}
	exit(EXIT_SUCCESS);
}
