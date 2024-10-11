class Solution {
public:
    string simplifyPath(string path) {
        // while loop or for loop
        // for each character
        //  if '/' (i)=> collect until not / (i+1)
        //  if '.' => collect until not .
        //  if normal name => collect until not normal name or .

        // then we handle different categories for each untils

        // '/' => just append a single slash
        // '.' => if . => remove .
        //     => if .. => remove .. as well as until either start of result or first 2 / 
        // normal => Add it

        std::string result;
        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/')  {
                while (i + 1 < path.size()) {
                   if (path[i+1] == '/') i++; 
                   else break;
                }

                while (!result.empty() && result.back() == '/') result.pop_back();
                result += "/";
                i++;
            } else if (path[i] == '.') {
                std::string temp_dots = ".";
                while (i + 1 < path.size()) {
                   if (path[i+1] != '/') {
                        temp_dots += path[i+1]; 
                        i++; 
                    } else break;
                }

                if (temp_dots == ".") {
                   i++;
                   if (result.size() > 1) result.pop_back();
                   continue; 
                } else if (temp_dots == "..") {

                    // Pop until either we reach the root or we have met at least two slashes

                    
                    if (result.size() > 1 ) {
                        result.pop_back();
                        while (result.size() != 1 && result.back() != '/') result.pop_back();
                        if (!(result.size() == 1 && result.back() == '/')) result.pop_back();
                        i++;
                        continue;
                    }
                    i++;
                    continue;
                } else {
                   result += temp_dots; 
                   i++;
                }
                
            } else {
                std::string temp_dir = "";
                temp_dir += path[i]; 
                while (i + 1 < path.size()) {
                   if (path[i+1] != '/') {
                        temp_dir += path[i+1]; 
                        i++; 
                    } else break;
                }


                result += temp_dir;

                i++;
            }

            std::cout << "Result : " << result << std::endl;


        }

        while (result.size() > 1 && result.back() == '/') result.pop_back();

        return result;
    }
};