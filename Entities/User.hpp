

namespace Discord::Entities {
    class User {
    public:
        unsigned long UserId;
        unsigned long RoleId;
        int UserCount;

        User();
        ~User();
    };
}