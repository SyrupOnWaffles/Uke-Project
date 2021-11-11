#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include<string>
#include<sstream>

using namespace std;
#define log(x) cout << x;
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
   test_init(al_reserve_samples(128), "reserve samples");
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
       al_load_sample("sounds/A.wav"), al_load_sample("sounds/E.wav"), al_load_sample("sounds/C.wav"), al_load_sample("sounds/G.wav")
};

   ALLEGRO_BITMAP *uke = al_load_bitmap("images/uke.png");
   test_init(uke, "uke");

   al_register_event_source(queue, al_get_keyboard_event_source());
   al_register_event_source(queue, al_get_mouse_event_source());
   al_register_event_source(queue, al_get_display_event_source(disp));
   al_register_event_source(queue, al_get_timer_event_source(timer));
   
   bool done = false;
   bool redraw = true;
   ALLEGRO_EVENT event;
   #define KEY_SEEN     1
   #define KEY_RELEASED 2

   unsigned char key[ALLEGRO_KEY_MAX];
   memset(key, 0, sizeof(key));
   int one = 0;
   int two = 0;
   int three = 0;
   int four = 0;
   al_start_timer(timer);
   while (1)
   {  
      
      float mean = ((one + two + three + four) / 4) - 1;
      one = 0;
      two = 0;
      three = 0;
      four = 0;
      al_wait_for_event(queue, &event);
      
      switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
               //yandere dev be like
               if(key[ALLEGRO_KEY_Z])
                  four = 1;
               if(key[ALLEGRO_KEY_X])
                  four = 2;
               if(key[ALLEGRO_KEY_C])
                  four = 3;
               if(key[ALLEGRO_KEY_V])
                  four = 4;
               if(key[ALLEGRO_KEY_B])
                  four = 5;
               if(key[ALLEGRO_KEY_N])
                  four = 6;
               if(key[ALLEGRO_KEY_M])
                  four = 7;
               if(key[ALLEGRO_KEY_A])
                  three = 1;
               if(key[ALLEGRO_KEY_S])
                  three = 2;
               if(key[ALLEGRO_KEY_D])
                  three = 3;
               if(key[ALLEGRO_KEY_F])
                  three = 4;
               if(key[ALLEGRO_KEY_G])
                  three = 5;
               if(key[ALLEGRO_KEY_H])
                  three = 6;
               if(key[ALLEGRO_KEY_J])
                  three = 7;
               if(key[ALLEGRO_KEY_Q])
                  two = 1;
               if(key[ALLEGRO_KEY_W])
                  two = 2;
               if(key[ALLEGRO_KEY_E])
                  two = 3;
               if(key[ALLEGRO_KEY_R])
                  two = 4;
               if(key[ALLEGRO_KEY_T])
                  two = 5;
               if(key[ALLEGRO_KEY_Y])
                  two = 6;
               if(key[ALLEGRO_KEY_U])
                  two = 7;
               if(key[ALLEGRO_KEY_1])
                  one = 1;
               if(key[ALLEGRO_KEY_2])
                  one = 2;
               if(key[ALLEGRO_KEY_3])
                  one = 3;
               if(key[ALLEGRO_KEY_4])
                  one = 4;
               if(key[ALLEGRO_KEY_5])
                  one = 5;
               if(key[ALLEGRO_KEY_6])
                  one = 6;
               if(key[ALLEGRO_KEY_7])
                  one = 7;
               if(key[ALLEGRO_KEY_ESCAPE ])
                  done = true;
                for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= KEY_SEEN;

                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                  //al_play_sample(noteSamples[3], 1.0, 0.0, 1.0 + (0.05946 * four), ALLEGRO_PLAYMODE_ONCE, NULL);
                  //al_rest(.1);
                  //al_play_sample(noteSamples[2], 1.0, 0.0, 1.0 + (0.05946 * three), ALLEGRO_PLAYMODE_ONCE, NULL);
                  //al_rest(.1);
                  //al_play_sample(noteSamples[1], 1.0, 0.0, 1.0 + (0.05946 * two), ALLEGRO_PLAYMODE_ONCE, NULL);
                  //al_rest(.1);
                  //al_play_sample(noteSamples[0], 1.0, 0.0, 1.0 + (0.05946 * one), ALLEGRO_PLAYMODE_ONCE, NULL);
                  
               
               
               key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
               if(event.keyboard.keycode == ALLEGRO_KEY_UP) cout << "test";
                
                break;
            case ALLEGRO_EVENT_KEY_UP:
                key[event.keyboard.keycode] &= KEY_RELEASED;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }


      if (done)
         break;

      if (redraw && al_is_event_queue_empty(queue))
      {
         al_clear_to_color(al_map_rgb(99, 155, 255));
         
         al_draw_scaled_bitmap(uke, 0, 0, 900, 750, 10, 100, 1200, 1000, 1);

         // Draw Strings
         al_draw_ellipse(650, 283, 355, .1, al_map_rgb(69, 40, 60), 3);
         al_draw_ellipse(650, 303, 355, .1, al_map_rgb(69, 40, 60), 3);
         al_draw_ellipse(650, 323, 355, .1, al_map_rgb(69, 40, 60), 3);
         al_draw_ellipse(650, 343, 355, .1, al_map_rgb(69, 40, 60), 3);
         

         //Fret Markers
         al_draw_filled_circle(275 + one * 40, 283, 10, al_map_rgb(172, 50, 50));
         al_draw_filled_circle(275 + two * 40, 303, 10, al_map_rgb(172, 50, 50));
         al_draw_filled_circle(275 + three * 40, 323, 10, al_map_rgb(172, 50, 50));
         al_draw_filled_circle(275 + four * 40, 343, 10, al_map_rgb(172, 50, 50));
         std::stringstream ss;
         ss << four << three << two << one;
         std::string strNum = ss.str();
         const char * c = strNum.c_str();
         al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, c);


         al_flip_display();

         redraw = false;
      }
      
   }

   // Destruction
   al_destroy_bitmap(uke);
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
