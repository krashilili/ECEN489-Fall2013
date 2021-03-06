//============================================================================
// Name        : AccerPos.cpp
// Author      : shuli
// Version     :
// Copyright   : IMU
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	double t=0.1;
	int i;
	int n;
	double Accel_x[]={-10.24,-7.17,-7.17,-10.24,-13.31,-64.51,-71.68,-98.3,-22.53,2.05,-8.19,
			72.7,
			16.38,
			53.25,
			47.1,
			-93.18,
			-265.22,
			-317.44,
			-100.35,
			-88.06,
			-64.51,
			-51.2,
			-30.72,
			16.38,
			27.65,
			7.17,
			5.12,
			6.14,
			61.44,
			-28.67,
			-166.91,
			-238.59,
			-101.38,
			-82.94,
			-65.54,
			-68.61,
			-51.2,
			-10.24,
			5.12,
			29.7,
			40.96,
			37.89,
			181.25,
			-43.01,
			-150.53,
			-126.98,
			-114.69,
			-55.3,
			-20.48,
			-34.82,
			-22.53,
			-18.43,
			-46.08,
			-29.7,
};
	double Accel_y[]={-228.35,
	                -227.33,
	                -225.28,
	                -226.3,
	                -211.97,
	                -149.5,
	                -174.08,
	                -190.46,
	                -147.46,
	                -48.13,
	                -52.22,
	                36.86,
	                -102.4,
	                -45.06,
	                10.24,
	                -10.24,
	                -155.65,
	                -83.97,
	                29.7,
	                25.6,
	                88.06,
	                65.54,
	                4.1,
	                32.77,
	                23.55,
	                -26.62,
	                -60.42,
	                -19.46,
	                62.46,
	                -39.94,
	                -110.59,
	                12.29,
	                72.7,
	                2.05,
	                49.15,
	                7.17,
	                36.86,
	                33.79,
	                -21.5,
	                -46.08,
	                -10.24,
	                68.61,
	                158.72,
	                121.86,
	                46.08,
	                -3.07,
	                0,
	                -33.79,
	                6.14,
	                18.43,
	                20.48,
	                35.84,
	                30.72,
	                54.27,
	};
	double Accel_z[]={
			98.3,
			104.45,
			101.38,
			101.38,
			77.82,
			161.79,
			174.08,
			163.84,
			317.44,
			312.32,
			275.46,
			214.02,
			47.1,
			11.26,
			112.64,
			73.73,
			99.33,
			116.74,
			357.38,
			377.86,
			261.12,
			208.9,
			181.25,
			205.82,
			153.6,
			78.85,
			49.15,
			130.05,
			225.28,
			218.11,
			217.09,
			17.41,
			219.14,
			391.17,
			263.17,
			215.04,
			197.63,
			135.17,
			83.97,
			77.82,
			147.46,
			48.13,
			404.48,
			470.02,
			202.75,
			167.94,
			150.53,
			194.56,
			157.7,
			192.51,
			212.99,
			217.09,
			174.08,
			208.9,
	};

	double PosX[55];
	double PosY[55];
	double PosZ[55];
	double VelX[55];
	double VelY[55];
	double VelZ[55];
	double PositionX=0;
	double PositionY=0;
	double PositionZ=0;
	for (n=1;n<56;n++){
		PositionX=0;
		PositionY=0;
		PositionZ=0;
		for (i=0;i<n;i++)
		{
		PosX[0]=0;
		PosY[0]=0;
		PosZ[0]=0;
		VelX[0]=0;
		VelY[0]=0;
		VelZ[0]=0;
		PosX[i+1]=VelX[i]*t+0.5*Accel_x[i]*t*t;
		PosY[i+1]=VelY[i]*t+0.5*Accel_y[i]*t*t;
		PosZ[i+1]=VelZ[i]*t+0.5*Accel_z[i]*t*t;
		VelX[i+1]=VelX[i]+Accel_x[i]*t;
		VelY[i+1]=VelY[i]+Accel_y[i]*t;
		VelZ[i+1]=VelZ[i]+Accel_z[i]*t;
		//cout<<Pos[i]<<endl;
		PositionX += PosX[i];
		PositionY += PosY[i];
		PositionZ += PosZ[i];
		}
		//cout<<"PositionX="<<PositionX<<endl;
		//cout<<"PositionY="<<PositionY<<endl;
		cout<<"PositionZ="<<PositionZ<<endl;
	}

}
