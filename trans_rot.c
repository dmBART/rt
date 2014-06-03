/*
** trans_rot.c for trans_rot in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Wed Mar 12 08:48:31 2014 Thibault Woivre
** Last update Fri May 30 14:39:21 2014 dylan manin
*/

#include	"mlxwin.h"

int		rotate_x(t_pos *xyz, double angle)
{
  double	y;
  double	z;

  y = xyz->y;
  z = xyz->z;
  xyz->y = cos(angle) * y - sin(angle) * z;
  xyz->z = sin(angle) * y + cos(angle) * z;
  return (0);
}

int		rotate_y(t_pos *xyz, double angle)
{
  double	x;
  double	z;

  x = xyz->x;
  z = xyz->z;
  xyz->x = cos(angle) * x + sin(angle) * z;
  xyz->z = cos(angle) * z - sin(angle) * x;
  return (0);
}

int		rotate_z(t_pos *xyz, double angle)
{
  double	x;
  double	y;

  x = xyz->x;
  y = xyz->y;
  xyz->x = cos(angle) * x - sin(angle) * y;
  xyz->y = sin(angle) * x + cos(angle) * y;
  return (0);
}

int             translation_xyz(t_pos *xyz, t_pos translation)
{
  xyz->x -= translation.x;
  xyz->y -= translation.y;
  xyz->z -= translation.z;
  return (0);
}

int             rotate_trans(t_pos *xyz, t_win *mw, int i)
{
  translation_xyz(xyz, mw->tab_obj[i].trans);
  rotate_z(xyz, -mw->tab_obj[i].rot.z);
  rotate_y(xyz, -mw->tab_obj[i].rot.y);
  rotate_x(xyz, -mw->tab_obj[i].rot.x);
  //  rotate_z(&mw->p_oeil, -mw->tab_obj[i].rot.z);
  //rotate_y(&mw->p_oeil, -mw->tab_obj[i].rot.y);
  //rotate_x(&mw->p_oeil, -mw->tab_obj[i].rot.x);
  return (0);
}
