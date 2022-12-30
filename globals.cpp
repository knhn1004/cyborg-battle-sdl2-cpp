#include "globals.h"

namespace globals {

const float PI = M_PI;

bool debugging = true;

int screenWidth = 640, screenHeight = 352, screenScale = 2;

SDL_Renderer *renderer = nullptr;

std::string clipOffDataHeader(std::string data) {
    int pos = data.find(":", 0);

    if (pos != std::string::npos) {
        return data.substr(pos + 2);
    } else {
        std::cout << "Error: could not find data header in " << data << std::endl;
        return "";
    }
}

} // namespace globals