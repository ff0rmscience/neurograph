#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define M 200
#define MAX_DATA 1000
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#define SCREEN_W 2400
#define SCREEN_H 1600
#define pixels_per_unit 100
#define PI 3.14159265359
#define WEIGHT_LIMIT 1

//df neural network variables
enum {LINEAR,TANH, RELU, SWISH, SIN};
typedef double real;typedef unsigned int nat;
union nat_real_string {int integer; real floating; char* str[10];};
union nat_real_string setting_content[40];
int data_mode = 1;
int gray_intensity = 100,structure_L = 500, structure_D = 800;
int s_height = 30,DOWN = 355,LEFT = 500,num_F_codes =100,F_code = 0;
int pixel_width = 17, pixel_height = 17,plot_slow = 10;
int offset = 80,current_setting = 0,structure_W = 600, structure_H = 500;
int menu_left = 1100, menu_down = 340, hide_menu = 0, thickness = 3;
real W[M][M],dW[M][M],z[M],a[M],da[M],b[M],db[M],p[M][2],data[MAX_DATA][2];
real delta[M],mean_error = 0.0, noise = .3;
int d[200],C[M][M],L, N, batch_size, image_size=100, neurons_in_layer[10];
int number_of_settings = 20, number_of_basic_settings = 20, number_of_extended_settings=34,batch_size_increment = 20;
real amplify_increment = 0.01, sample_lower_bound = -1.0,sample_upper_bound = 1.0,rate = 0.005,rate_increment = 0.01;
real amplify;
int stats_left = 0, stats_down = 340, struct_mode = 0; struct_modes = 3;
int layer_transfer[M],transfer_types = 5,keyboard_input, data_points = 100;
real left = -PI,right = PI,domain_increment = 0.2, max_f = 2.0,max_weight = 20;
int display_mode = 0, menu_items = 4, menu_flag = 0;
int max_neurons_in_layer = 30,show_F_flag = 1,font_size = 30,big_font_size = 60,key_down = 195,key_left = 1370;
char* trans_desc[10] =
{
	"   id ",
	" tanh ",
	" relu ",
	" swsh ",
	"  sin "
};
int setting_code[40] =
{1,1,0,0,0,
 0,0,0,0,2,
 2,2,2,2,2,
 0,0,1,0,0,
 0,0,0,0,0,
 0,0,0,0,0,
 0,0,0,0,0,
 0,0};
//0 for nat, 1 for float, 2 for string
char* setting_desc[40] = {
"learning rate    =",
"scale output     =",
"batch            =",
"nodes in lay 0   =",
"nodes in lay 1   =",
"nodes in lay 2   =",
"nodes in lay 3   =",
"nodes in lay 4   =",
"nodes in lay 5   =",
"act fn lay 0     =",
"act fn lay 1     =",
"act fn lay 2     =",
"act fn lay 3     =",
"act fn lay 4     =",
"act fn lay 5     =",
"target fn  code  =",
"num examples     =",
"noise level      =",
"data mode        =",
"menu mode        =",
"plot right pos   =",
"plot down pos    =",
"struct width     =",
"struct height    =",
"struct right pos =",
"struct down pos  =",
"plot size        =",
"sttngs right pos =",
"sttngs down pos  =",
"display mode     =",
"struct mode      =",
"pix height       =",
"pix width        =",
"thickness        ="
};

char* menu_choice[20] = {
	"(w)     new random weights",
	"(r)     reset to default  ",
	"(l/L)   adjust function plot",
	"(d/D)   adjust function plot"
};

// allegro variables
ALLEGRO_EVENT_QUEUE *q;
ALLEGRO_FONT* font;
ALLEGRO_FONT* big_font;
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT event;
ALLEGRO_COLOR white, red, black, blue, green, yellow, gray,current_color, orange;
ALLEGRO_COLOR transfer_color[10];


void install_connections();
void erase_structure();
void plot_structure(real,real,real,real);
void display_setting(nat);
void erase_settings();
void initialize_weights(real, real);
real random_double(real,real);
real f(real);
void display_settings();
void install_structure(int, int);
void display_key();
void respond_to_input();
void set_up_network();
void flush_network();
void reset();
void set_up_graphics();
void plot_functions(float,float,int);
void plot_function_against_data(float,float,int);
void erase_functions(float,float,int);
real F(int, real);
void update_parameters();
void backpropagate(real);
int key_pressed();
void erase_settings();
void display_mean_error();
void load_new_data();
void load_setting_content();
void show_menu();

real random_normal(real,real);
