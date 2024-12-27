#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    int     width;
    int     height;
    int     color;
}   t_data;

void fill_image(t_data *data, int color)
{
    int x, y;

    for (y = 0; y < data->height; y++)
    {
        for (x = 0; x < data->width; x++)
        {
            char *pixel = data->addr + (y * data->line_length + x * (data->bpp / 8));
            *(unsigned int *)pixel = color; // Écrit la couleur dans le pixel
        }
    }
}

int close_window(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307) // Touche Échap
        close_window(data);
    else if (keycode == 32) // Touche espace
    {
        // Change la couleur aléatoirement
        data->color = rand() % 0xFFFFFF;
        fill_image(data, data->color); // Remplit l'image avec la nouvelle couleur
        mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    }
    return (0);
}

int main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    if (!data.mlx)
    {
        fprintf(stderr, "Erreur : Échec de l'initialisation de mlx.\n");
        return (1);
    }
    data.width = 800;
    data.height = 600;
    data.win = mlx_new_window(data.mlx, data.width, data.height, "Fenêtre avec image");
    if (!data.win)
    {
        fprintf(stderr, "Erreur : Échec de la création de la fenêtre.\n");
        return (1);
    }
    data.img = mlx_new_image(data.mlx, data.width, data.height);
    if (!data.img)
    {
        fprintf(stderr, "Erreur : Échec de la création de l'image.\n");
        return (1);
    }
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
    data.color = 0x0000FF; // Couleur initiale : bleu

    fill_image(&data, data.color); // Remplit l'image avec la couleur initiale
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    mlx_hook(data.win, 17, 0, close_window, &data); // Fermer la fenêtre avec la croix
    mlx_key_hook(data.win, key_hook, &data);       // Gestion des touches clavier
    mlx_loop(data.mlx);
    return (0);
}

