#ifndef __BSQ_H__
# define __BSQ_H__

void print_result_board(int **grid, int position[2], int square_size, int size[2], char char_type[3]);
void create_width_tab(int **grid, int **width_tab, int size[2]);
void get_max_size_tab(int **width_tab, int **size_tab, int size[2]);
void get_max_sq_position(int **max_size_tab, int position[2], int max_size[1], int size[2]);
int  get_file_parameters(char* filename, int size[2], char char_type[3], int is_windows);
int  is_map_correct(char *filename, int size[2], char char_type[3], int is_windows);
int  create_grid(char *filename, int size[2], char char_type[3], int **tab, int is_windows);
void read_write_stdin();
void throw_map_error();


void ft_putchar(char c);
int ft_atoi(char *str);

#endif

