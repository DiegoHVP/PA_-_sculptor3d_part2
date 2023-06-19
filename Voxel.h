#ifndef VOXEL_H
#define VOXEL_H

/**
 * @struct Voxel
 * @brief Estrutura que representa um voxel.
 *
 * Um voxel possui informações sobre suas cores (r, g, b), transparência (a) e se está visível (show).
 */
struct Voxel {
  float r; /**< Componente de cor vermelha. */
  float g; /**< Componente de cor verde. */
  float b; /**< Componente de cor azul. */
  float a; /**< Transparência. */
  bool show; /**< Indica se o voxel está visível. */
};

#endif // VOXEL_H


