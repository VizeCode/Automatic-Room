enum ExceptionType
{
    TIMEOUT, CONNECTION, NILL
};

struct Exception
{
    ExceptionType t;
    String desc;
    Console console;

    void config(Console c)
    {
        console = c;
    }

    String format()
    {
        String error;
        String final;
        int num;
        
        switch (t)
        {
            case TIMEOUT:
                error = "TIMEOUT";
                num = 1;
                break;
            case CONNECTION:
                error = "CONNECTION";
                num = 2;
                break;
            default:
                error = "NULL";
                num = 0;
                break;
        }

        return "Exception(" + String(num) + ") " + error;
    }

    void launch(ExceptionType type)
    {
        t = type;
        console.sendMessage(format());
        return;
    }

    void launch(ExceptionType type, String desc)
    {
        t = type;
        String message = format();
        message += ": " + desc;
        console.sendMessage(message);
        return;
    }
};
