
class Core
{
public:
	static unsigned int version() {

        if (__cplusplus == 199711L) {
            return 3;
        }
        else if (__cplusplus == 201103L) {
            return 11;
        }
        else if (__cplusplus == 201402L) {
            return 14;
        }
        else if (__cplusplus == 201703L) {
            return 17;
        }
        else if (__cplusplus == 202002L) {
            return 20;
        }
        else {
            return 0;
        }
	}
};