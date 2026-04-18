#include <string> // for std::string

#include <curl/curl.h> // for curl HTTP requests
#include <nlohmann/json.hpp> // for JSON parsing

#include "fpl_client.h" // for FPLClient class

namespace FPL_Squad_Picker
{   

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::vector<Player> FPLClient::fetch_players()
{
    CURL* curl = curl_easy_init();
    std::string buffer;

    curl_easy_setopt(curl, CURLOPT_URL,
        "https://fantasy.premierleague.com/api/bootstrap-static/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    json data = json::parse(buffer);

    std::vector<Player> players;

    for (auto& p : data["elements"])
    {
        Player player;

        player.id = p["id"];
        player.name =
            p["first_name"].get<std::string>() + " " +
            p["second_name"].get<std::string>();

        player.team = p["team"];
        player.position = p["element_type"];
        player.price = p["now_cost"];
        player.total_points = p["total_points"];
        player.points_per_game = std::stod(p["points_per_game"].get<std::string>());
        player.minutes = p["minutes"];

        players.push_back(player);
    }

    return players;
}

} // namespace FPL_Squad_Picker