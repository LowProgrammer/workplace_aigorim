package com.utils;

/**
 * 状态码 0数据库插入异常 1 在黑名单中 2数据库存储过程出现问题  3成功
 * @author feifei
 * @Classname ConstantUtils
 * @Description TODO
 * @Date 2019/11/29 11:00
 * @Created by 陈群飞
 */
public enum  ConstantUtils {
    SUCCESS(200,"成功"),
    SUCCESS_ADD_OR_UPDATE(201,"用户新建或者修改数据成功"),
    SUCCESS_ACCEPTED(204,"请求进入后台，等待操作"),
    ERROR(400,"请求错误"),
    ERROR_NOAUTHORITION(401,"该用户没有权限操作"),
    ERROR_FORBIDDEN(403,"禁止访问"),
    ERROR_NOT_FOUND(404,"找不到请求的资源"),
    ERROR_NOT_ACCEPTABLE(406,"请求的格式不正确"),
    ERROR_GONE(410,"请求地址已更改，请检查"),
    ERROR_SERVER(500,"内部服务器错误"),
    ;


    private int code;
    private String note;

    private ConstantUtils(int code,String note){
        this.code=code;
        this.note=note;
    }

    public int getCode() {
        return code;
    }

    public void setCode(int code) {
        this.code = code;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}
