// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   debug.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/15 17:25:27 by plachard          #+#    #+#             */
// /*   Updated: 2025/03/21 16:47:49 by aderison         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"

// static void print_textures(t_textures tex) {
//     printf("Textures:\n");

//     // Vérification pour north
//     if (tex.north != NULL)
//         printf("  North: %s\n", tex.north);
//     else
//         printf("  North: Non défini\n");

//     // Vérification pour south
//     if (tex.south != NULL)
//         printf("  South: %s\n", tex.south);
//     else
//         printf("  South: Non défini\n");

//     // Vérification pour west
//     if (tex.west != NULL)
//         printf("  West: %s\n", tex.west);
//     else
//         printf("  West: Non défini\n");

//     // Vérification pour east
//     if (tex.east != NULL)
//         printf("  East: %s\n", tex.east);
//     else
//         printf("  East: Non défini\n");

//     // Vérification pour floor
//     if (tex.floor != NULL)
//         printf("  Floor color: [%d, %d, %d]\n", tex.floor[0], tex.floor[1], tex.floor[2]);
//     else
//         printf("  Floor color: Non défini\n");

//     // Vérification pour ceiling
//     if (tex.ceiling != NULL)
//         printf("  Ceiling color: [%d, %d, %d]\n", tex.ceiling[0], tex.ceiling[1], tex.ceiling[2]);
//     else
//         printf("  Ceiling color: Non défini\n");

//     // Hexadecimal floor et ceiling
//     printf("  Hex Floor: %#x\n", tex.hex_floor);
//     printf("  Hex Ceiling: %#x\n", tex.hex_ceiling);

//     // Affichage des autres propriétés
//     printf("  Size: %d\n", tex.size);
//     printf("  Position X: %d\n", tex.x);
//     printf("  Position Y: %d\n", tex.y);
//     printf("  Step: %f\n", tex.step);
//     printf("  Position: %f\n", tex.pos);
//     printf("  Index: %d\n", tex.index);
// }

// static void print_map(t_map map) {
//     printf("Map:\n");

//     // Vérification pour matrice
//     if (map.matrice != NULL) {
//         printf("  Matrice:\n");
//         for (int i = 0; i < map.height; i++) {
//             if (map.matrice[i] != NULL) {
//                 printf("    %s\n", map.matrice[i]);
//             } else {
//                 printf("    Ligne %d: Non défini\n", i);
//             }
//         }
//     } else {
//         printf("  Matrice: Non défini\n");
//     }

//     // Affichage des autres propriétés
//     printf("  Width: %d\n", map.width);
//     printf("  Height: %d\n", map.height);
// }

// static void print_player(t_player player) {
//     printf("Player:\n");
//     printf("  Position X: %f\n", player.x);
//     printf("  Position Y: %f\n", player.y);
//     printf("  movex: %d\n", player.movex);
//     printf("  movey: %d\n", player.movey);
//     printf("  Direction X: %f\n", player.dirx);
//     printf("  Direction Y: %f\n", player.diry);
//     printf("  Plane X: %f\n", player.planex);
//     printf("  Plane Y: %f\n", player.planey);
//     printf("  Rotate: %d\n", player.rotate);
//     printf("  Is in move: %d\n", player.is_in_move);
// }

// void print_cub3d(t_cub3d *cub3d) {
//     printf("Cub3D Data:\n");

//     // Vérification pour les données
//     if (cub3d->data != NULL) {
//         printf("  Data:\n");
//         for (int i = 0; cub3d->data[i] != NULL; i++) {
//             printf("    %s\n", cub3d->data[i]);
//         }
//     } else {
//         printf("  Data: Non défini\n");
//     }

//     // Affichage des autres structures
//     print_player(cub3d->player);
//     write(1, "\n", 1);
//     print_map(cub3d->map);
//     write(1, "\n", 1);
//     print_textures(cub3d->datatex);
// }
