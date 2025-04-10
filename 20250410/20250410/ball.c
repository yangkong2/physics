#include <stdio.h>
#include <math.h>


int main()
{
	//0. 변수 선언
	double g = 9.8; // 중력가속도 (m/s^2)
	double a = -g; // 가속도 = -중력가속도
	double theta_deg; // 각도 (도)
	double v0 = 0; // 초기속도 (m/s)
	double PI = 3.141592; // 파이 = 3.141592;
	double theta_rad; // 라디안 

	printf("각도를 입력하세요 ==> ");
	scanf_s("%lf", &theta_deg);

	printf("초기속도를 입력하세요 ==> ");
	scanf_s("%lf", &v0);

	//1. x,y 방향의 초기 속도 구하기

	double v0x;
	double v0y;

	theta_rad = theta_deg * PI / 180;

	v0x = v0 * cos(theta_deg);
	// printf("%lf\n", vx);
	v0y = v0 * sin(theta_deg);
	// printf("%lf\n", v0y);

//2. 최고점의 높이를 구하여라

	double H; // 높이
	double t; // 시간

	// 물체가 최고점에 도달할 때의 속도 = vy = 0;

	t = v0y / g;


	//y = y0 + v0y * t + 0.5 * g * t * t 에서 y = H, y0 = 0

	H = v0y * t + (g * t * t) / 2;  // y = y0 + v0yt + 1/2gt^2

	//3. 최고점에 도착하는 시간을 구하여라

	t = v0y / g;

	//4. 수평으로 이동한 최고 거리를 구하여라

	double x; // 거리

	x = v0x * t * 2; // 현재 t의 값이 최고점으로 갈 때 까지의 높이 * 초기속도 * 2


	//5. 지면에 닿을때의 vx, vy를 구하고 v를 벡터 성분을 구하여라

	double vx;
	double vy;

	vx = v0x;

	vy = v0y + a * 2 * t; // 여기서의 t는 최고점까지 도달하는데 걸리는 시간이므로  2t

	// printf("%lf\n", vy);

	double v_rad;
	double v_deg;
	double v;

	v_rad = atan2(vy, vx);
	v_deg = v_rad * 180 / PI;


	v = sqrt(vx * vx + vy * vy);

	// printf("%lf, %lf", v_deg, v);

	printf("지면에 닿을 때 x 방향 속도: %.2f m/s\n", vx);
	printf("지면에 닿을 때 y 방향 속도: %.2f m/s\n", vy);
	printf("지면에 닿을 때 속도 크기: %.2f m/s\n", v);

	printf("속도 벡터 성분 : (%.2fm/s, %.2f°)\n", v, v_deg);
}