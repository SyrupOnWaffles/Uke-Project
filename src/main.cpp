#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>
#define KEY_SEEN 1
#define KEY_RELEASED 2
using namespace std;
#define log(x) cout << x;
void draw_sin(int length, float amplitude, int xoffset, int yoffset, ALLEGRO_COLOR colour, float thickness)
{
   for (int i = 1; i <= length; i++)
   {
      al_draw_filled_circle(floor(i) + xoffset, floor(sin(i) * amplitude + yoffset), thickness, colour);
   }
}
void test_init(bool test, string message)
{
   if (!test)
   {
      log("couldn't initialize " << message << "\n");
   }
}
int main()
{

   // Instantiation
   test_init(al_init(), "allegro");
   test_init(al_install_keyboard(), "keyboard");
   test_init(al_init_image_addon(), "image addon");
   test_init(al_init_primitives_addon(), "primative addon");
   test_init(al_install_audio(), "audio");
   test_init(al_init_acodec_addon(), "audio codecs");
   test_init(al_reserve_samples(32), "reserve samples");
   test_init(al_install_mouse(), "mouse");

   ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60);
   test_init(timer, "timer");
   ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
   test_init(queue, "queue");
   ALLEGRO_DISPLAY *disp = al_create_display(1280, 720);
   test_init(disp, "display");
   ALLEGRO_FONT *font = al_create_builtin_font();
   test_init(font, "font");

   ALLEGRO_SAMPLE *noteSamples[4] = {
       al_load_sample("sounds/A.wav"), al_load_sample("sounds/E.wav"), al_load_sample("sounds/C.wav"), al_load_sample("sounds/G.wav")};

   ALLEGRO_BITMAP *uke = al_load_bitmap("images/uke.png");
   test_init(uke, "uke");
   ALLEGRO_BITMAP *background = al_load_bitmap("images/background.png");
   test_init(background, "background");
   ALLEGRO_BITMAP *dot = al_load_bitmap("images/dot.png");
   test_init(dot, "dot");
   ALLEGRO_BITMAP *icon = al_load_bitmap("images/windowicon.png");
   test_init(icon, "icon");
   al_register_event_source(queue, al_get_keyboard_event_source());
   al_register_event_source(queue, al_get_display_event_source(disp));
   al_register_event_source(queue, al_get_timer_event_source(timer));
   al_register_event_source(queue, al_get_mouse_event_source());

   bool done = false;
   bool redraw = true;
   ALLEGRO_EVENT event;
   unsigned char key[ALLEGRO_KEY_MAX];
   memset(key, 0, sizeof(key));
   int one;
   int two;
   int three;
   int four;
   int prevUp;
   int x = 1280;
   int y = 720;
   float oneVibration = 0;
   float twoVibration = 0;
   float threeVibration = 0;
   float fourVibration = 0;

   bool fourPlaying;
   bool threePlaying;
   bool twoPlaying;
   bool onePlaying;
   al_set_display_icon(disp,icon);
   al_start_timer(timer);
   while (1)
   {

      float mean = ((one + two + three + four) / 4) - 1;
      al_wait_for_event(queue, &event);

      switch (event.type)
      {

      case ALLEGRO_EVENT_TIMER:
         oneVibration -= .04;
         twoVibration -= .04;
         threeVibration -= .04;
         fourVibration -= .04;
         if (oneVibration < 0)
            oneVibration = 0;
         if (twoVibration < 0)
            twoVibration = 0;
         if (threeVibration < 0)
            threeVibration = 0;
         if (fourVibration < 0)
            fourVibration = 0;
         one = 0;
         two = 0;
         three = 0;
         four = 0;
         // yandere dev be like
         if (key[ALLEGRO_KEY_Z])
            four = 1;
         if (key[ALLEGRO_KEY_X])
            four = 2;
         if (key[ALLEGRO_KEY_C])
            four = 3;
         if (key[ALLEGRO_KEY_V])
            four = 4;
         if (key[ALLEGRO_KEY_B])
            four = 5;
         if (key[ALLEGRO_KEY_N])
            four = 6;
         if (key[ALLEGRO_KEY_M])
            four = 7;
         if (key[ALLEGRO_KEY_COMMA])
            four = 8;
         if (key[ALLEGRO_KEY_FULLSTOP])
            four = 9;
         if (key[ALLEGRO_KEY_SLASH])
            four = 10;
         if (key[ALLEGRO_KEY_A])
            three = 1;
         if (key[ALLEGRO_KEY_S])
            three = 2;
         if (key[ALLEGRO_KEY_D])
            three = 3;
         if (key[ALLEGRO_KEY_F])
            three = 4;
         if (key[ALLEGRO_KEY_G])
            three = 5;
         if (key[ALLEGRO_KEY_H])
            three = 6;
         if (key[ALLEGRO_KEY_J])
            three = 7;
         if (key[ALLEGRO_KEY_K])
            three = 8;
         if (key[ALLEGRO_KEY_L])
            three = 9;
         if (key[ALLEGRO_KEY_SEMICOLON])
            three = 10;
         if (key[ALLEGRO_KEY_Q])
            two = 1;
         if (key[ALLEGRO_KEY_W])
            two = 2;
         if (key[ALLEGRO_KEY_E])
            two = 3;
         if (key[ALLEGRO_KEY_R])
            two = 4;
         if (key[ALLEGRO_KEY_T])
            two = 5;
         if (key[ALLEGRO_KEY_Y])
            two = 6;
         if (key[ALLEGRO_KEY_U])
            two = 7;
         if (key[ALLEGRO_KEY_I])
            two = 8;
         if (key[ALLEGRO_KEY_O])
            two = 9;
         if (key[ALLEGRO_KEY_P])
            two = 10;
         if (key[ALLEGRO_KEY_1])
            one = 1;
         if (key[ALLEGRO_KEY_2])
            one = 2;
         if (key[ALLEGRO_KEY_3])
            one = 3;
         if (key[ALLEGRO_KEY_4])
            one = 4;
         if (key[ALLEGRO_KEY_5])
            one = 5;
         if (key[ALLEGRO_KEY_6])
            one = 6;
         if (key[ALLEGRO_KEY_7])
            one = 7;
         if (key[ALLEGRO_KEY_8])
            one = 8;
         if (key[ALLEGRO_KEY_9])
            one = 9;
         if (key[ALLEGRO_KEY_0])
            one = 10;

         if (key[ALLEGRO_KEY_ESCAPE])
            done = true;
         for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
            key[i] &= KEY_SEEN;

         redraw = true;
         break;

      case ALLEGRO_EVENT_KEY_DOWN:
         key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;

         break;
      case ALLEGRO_EVENT_KEY_UP:
         key[event.keyboard.keycode] &= KEY_RELEASED;
         break;
      case ALLEGRO_EVENT_MOUSE_AXES:
         x = event.mouse.x;
         y = event.mouse.y;
         if (prevUp != y)
         {
            // terrible collision (is this even collision detection?)
            if (y == 283 && x > 300 && x < 1000)
            {
               onePlaying = true;
            }
            if (y == 303 && x > 300 && x < 1000)
            {
               twoPlaying = true;
            }
            if (y == 323 && x > 300 && x < 1000)
            {
               threePlaying = true;
            }
            if (y == 343 && x > 300 && x < 1000)
            {
               fourPlaying = true;
            }
         }
         prevUp = event.mouse.y;
         break;
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
         done = true;
         break;
      }
      if (fourPlaying)
      {
         al_play_sample(noteSamples[3], 1.0, 0.0, 1.0 + (0.05946 * four), ALLEGRO_PLAYMODE_ONCE, NULL);
         fourVibration = 4;
         fourPlaying = false;
      }
      if (threePlaying)
      {
         al_play_sample(noteSamples[2], 1.0, 0.0, 1.0 + (0.05946 * three), ALLEGRO_PLAYMODE_ONCE, NULL);
         threeVibration = 4;
         threePlaying = false;
      }
      if (twoPlaying)
      {
         al_play_sample(noteSamples[1], 1.0, 0.0, 1.0 + (0.05946 * two), ALLEGRO_PLAYMODE_ONCE, NULL);
         twoVibration = 4;
         twoPlaying = false;
      }
      if (onePlaying)
      {
         al_play_sample(noteSamples[0], 1.0, 0.0, 1.0 + (0.05946 * one), ALLEGRO_PLAYMODE_ONCE, NULL);
         oneVibration = 4;
         onePlaying = false;
      }

      if (done)
         break;

      if (redraw && al_is_event_queue_empty(queue))
      {
         al_clear_to_color(al_map_rgb(38, 43, 68));
         al_draw_bitmap(background, 0, 0, 0);
         al_draw_scaled_bitmap(uke, 0, 0, 900, 750, 10, 100, 1200, 1000, 1);

         // Draw Strings
         draw_sin(710, oneVibration, 295, 283, al_map_rgb(139, 155, 180), 2);
         draw_sin(710, twoVibration, 295, 303, al_map_rgb(139, 155, 180), 2);
         draw_sin(710, threeVibration, 295, 323, al_map_rgb(139, 155, 180), 2);
         draw_sin(710, fourVibration, 295, 343, al_map_rgb(139, 155, 180), 2);

         // Fret Markers
         al_draw_bitmap(dot, 265 + one * 40, 273, 0);
         al_draw_bitmap(dot, 265 + two * 40, 293, 0);
         al_draw_bitmap(dot, 265 + three * 40, 313, 1);
         al_draw_bitmap(dot, 265 + four * 40, 333, 2);

         al_flip_display();

         redraw = false;
      }
   }

   // Destruction
   al_destroy_bitmap(uke);
   al_destroy_bitmap(background);
   al_destroy_bitmap(icon);
   al_destroy_bitmap(dot);

   al_destroy_font(font);
   al_destroy_display(disp);
   al_destroy_timer(timer);
   al_destroy_event_queue(queue);
   for (int i = 0; i < 4; i++)
   {
      al_destroy_sample(noteSamples[i]);
   }

   return 0;
}
