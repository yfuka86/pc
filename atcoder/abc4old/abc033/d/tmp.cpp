// 偏角ソート
// 与えられた中心と点集合に対して、偏角のリストを返す
vector<Real> arg_sort(Point &a , Points ps){
  vector<Real> ret;
  for(Point& p : ps) if(a != p) ret.push_back(atan2(p.imag() - a.imag(), p.real() - a.real()));
  sort(begin(ret) , end(ret));
  return ret;
};
