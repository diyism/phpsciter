//
// Created by zhanglei on 2020/5/16.
//

#ifndef PHPSCITER_SCITER_ZEND_API_H
#define PHPSCITER_SCITER_ZEND_API_H

namespace phpsciter{
    class ZendApi :public NoCopy{
    public:
        //编译
        zend_op_array *zendCompileFile(const char *file_name);

        //执行
        bool zendExecute();

        std::string& getBuffer()
        {
            return buffer;
        }

    private:

        std::string buffer;

#if PHP_VERSION_ID < 70000

        zval ** __old_return_value_pp;

        zend_op ** __old_opline_ptr;

        zend_op_array * __old_op_array;

        void storeOldExecuteInfo()
        {
            __old_return_value_pp   = EG(return_value_ptr_ptr);
            __old_opline_ptr  	= EG(opline_ptr);
            __old_op_array  = EG(active_op_array);
        }

        void reStoreOldExecuteInfo()
        {
            EG(return_value_ptr_ptr) = __old_return_value_pp;
            EG(opline_ptr)			 = __old_opline_ptr;
            EG(active_op_array)		 = __old_op_array;
        }
#endif
    };
}

#endif //PHPSCITER_SCITER_ZEND_API_H
