#include <glog/logging.h>
#include <gflags/gflags.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <boost/lexical_cast.hpp>


DEFINE_string(in, "", "input file. libsvm format");
DEFINE_string(out, "" , "output file. dimmwitted format");

std::string parse_line(std::string& line) {
  CHECK(!line.empty());
  std::stringstream ss(line);
  std::string str;
  std::vector<std::string> eles;

  while(std::getline(ss, str, ' ')) { 
    eles.push_back(str);
  }

  std::string ret = "";
  int lab = boost::lexical_cast<int>(eles[0]);
  if (lab == 0) { 
    ret += "-1 ";
  } else { 
    ret += "+1 ";
  }

  for(size_t i = 1;i < eles.size();i ++) { 
    ret += eles[i] + ":1 ";
  }
  return ret;
}



int main(int argc, char **argv) { 

  google::ParseCommandLineFlags(&argc, &argv, false);

  std::string in = FLAGS_in;
  std::string out = FLAGS_out;

  std::ifstream ifs(in.c_str(), std::ios_base::in | std::ios_base::binary);
  std::ofstream ofs(out.c_str(), std::ios_base::out | std::ios_base::binary);

  std::string line;
  std::string dwline;
  while(std::getline(ifs, line)) { 
    dwline = parse_line(line);

    ofs << dwline << "\n";
  }

  ifs.close();
  ofs.close();
 
  return 0;
}
