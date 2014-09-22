class Solution {
public:
bool isNumber (char const* s) {
char* endptr;
72 􀖻 3 􁅣 􁈳􀚘􀔱
strtod (s, &endptr);
if (endptr == s) return false;
for (; *endptr; ++endptr)
if (!isspace (*endptr)) return false;
return true;
}
};