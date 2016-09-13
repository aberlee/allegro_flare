



#include <allegro_flare/random.h>




Random::Random(unsigned int seed)
{}




void Random::set_seed(unsigned int new_seed)
{
   seed = new_seed;
   random_number_generator.seed(seed);
}




unsigned int Random::get_seed()
{
   return seed;
}




int Random::get_random_int(int max, int min)
{
   std::uniform_int_distribution<int> dist(min, max);
   return dist(random_number_generator);
}




float Random::get_random_float(float max, float min)
{
   std::uniform_real_distribution<float> dist(min, max);
   return dist(random_number_generator);
}




bool Random::get_one_in_chance(int chance)
{
   if (get_next_int(chance - 1) == 0)
      return true;
   return false;
}




int Random::roll_dice(int number_of_die, int sides)
{
   int result = 0;
   for (int i = 0; i < number_of_die; i++)
      result += get_next_int(sides, 1);
   return result;
}

