# *****************************************************
#     > Do Androids Dream of Electric Sheep? 
#     > File Name   :  push_master.sh
#     > Author      :  spike
#     > Email       :  Gehirn@yeah.net
#     > Create time :  CST 09:44:23 2020/07/16 四
#     > Comment     :
# *****************************************************

if [ ${#1} -ne 0 ]; then
    echo -n "Are you sure to commit ? (y/n) : "
    read confirm
    if [ $confirm ];then
        if [ $confirm = "y" ] || [ $confirm = "Y" ];then
            git add .
            git commit -m "$1"
            git push
        fi
    fi
else 
    echo "Error : miss commit message."
fi

