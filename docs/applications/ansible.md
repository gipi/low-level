# Ansible

## Check properly a service is started

A pain point with `ansible` is that a lot of time is not catching misconfiguration
because using a handler doesn't actualy fail because of problems since the service
might try multiple time to restart itself or the failure happens lately.

This below is an attempt of catching a failed restarted system, triggering the flushing
of the handlers and actually checking that is started.

```
- name: (Re-)start properly and check for service health
  block:
    - name: Force all notified handlers to run at this point, not waiting for normal sync points
      ansible.builtin.meta: flush_handlers
    - name: Reload systemd daemon
      ansible.builtin.systemd:
        daemon_reload: true
    # just above we checked it restarted but doesn't imply it remained started :P
    - name: Actually check {{ service_name }} service actually started
      ansible.builtin.service:
       name: "{{ service_name }}"
       state: started
       enabled: yes
  rescue:
    - name: Dump service error
      shell: "systemctl status {{ service_name }}"
      register: err_msg
      ignore_errors: True
    - name: Stop because of the error
      ansible.builtin.fail:
        msg: "{{ err_msg.stdout_lines|join('\n') }}"
  vars:
    service_name: filebeat
```

## Gathering info from extra nodes

You have a playbook with a `hosts` section but you need information about hosts not included there.
This can be problematic in particular when you are running a limited subset of the complete hosts
filtering with tags or using `--start-at-task` since the gathering of information doesn't happen for
those hosts

```
- name: Gather information from needed hosts
  ansible.builtin.setup:
  delegate_to: "{{ item }}"
  delegate_facts: true
  loop: "{{ some_list }}"
```
