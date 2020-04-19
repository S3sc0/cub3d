#include "cub3d.h"

void	initialize_triangle_points(player plr, data info)
{
	float	b;
	float	c;
	float	a;

	a = info.wx / 2;
	b = a / tan(30);
	c = pow(info.wx, 2) + pow(b, 2);
	c = sqrt(c);
	// initialize triangle's corners
	g_triangle_crnr1.x = plr.x;
	g_triangle_crnr2.x = plr.x;
	g_triangle_crnr1.y = plr.y;
	g_triangle_crnr2.y = plr.y;
	// calc the triangle's corners
	g_triangle_crnr1.x += c * cos((plr.rotationA - 30) * RADIN);
	g_triangle_crnr1.y += c * sin((plr.rotationA - 30) * RADIN);
	g_triangle_crnr2.x += c * cos((plr.rotationA + 30) * RADIN);
	g_triangle_crnr2.y += c * sin((plr.rotationA + 30) * RADIN);
	// correct the triangle's corners points if they are negative
	g_triangle_crnr1.x = g_triangle_crnr1.x < 0 ? 0 : g_triangle_crnr1.x;
	g_triangle_crnr1.y = g_triangle_crnr1.y < 0 ? 0 : g_triangle_crnr1.y;
	g_triangle_crnr2.x = g_triangle_crnr2.x < 0 ? 0 : g_triangle_crnr2.x;
	g_triangle_crnr2.y = g_triangle_crnr2.y < 0 ? 0 : g_triangle_crnr2.y;
	// correct the triangle's corners point if they are above the standards
	g_triangle_crnr1.x = g_triangle_crnr1.x > info.wx ? info.wx : g_triangle_crnr1.x;
	g_triangle_crnr1.y = g_triangle_crnr1.y > info.wy ? info.wy : g_triangle_crnr1.y;
	g_triangle_crnr2.x = g_triangle_crnr2.x > info.wx ? info.wx : g_triangle_crnr2.x;
	g_triangle_crnr2.y = g_triangle_crnr2.y > info.wy ? info.wy : g_triangle_crnr2.y;
}
