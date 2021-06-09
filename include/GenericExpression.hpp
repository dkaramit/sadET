#ifndef GenExpr_head
#define GenExpr_head

template<typename Type>
class GenericExpression{
    public:
    // This allows us to convert any expression to its sub-expressions, giving us access to their members. 
    static const Type& subExpression(const GenericExpression &expr)  
    {return  *static_cast<const Type*>(&expr);}
};

#endif