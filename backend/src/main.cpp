#include <iostream>

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      std::cout << "Give Configfilepath as argument" << std::endl;
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
