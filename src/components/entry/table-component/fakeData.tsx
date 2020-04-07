export const fakeData = {
  "info": {
    "graphs": [
      {
        "title": "已注册 Task Manager 数量",
        "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
      },
      {
        "title": "Task Slot 总数",
        "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
      },
      {
        "title": "Task Slot 可用数",
        "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
      },
      {
        "title": "运行中的 job 数量",
        "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
      },
      {
        "title": "JobManager live thread",
        "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
      },
      {
        "title": "JobManager Memory Available",
        "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
      }
    ],
    "namespace": "prophet-resource-huangzhen",
    "workspaceId": "10"
  },
  "items": [
    {
      "config": {
        "createTime": 1585900467000,
        "description": null,
        "entryClass": null,
        "flinkSql": "{\"conf\":{\"delay.interval\":10000,\"checkpoint.cleanup.mode\":false,\"failure.interval\":600000,\"state.backend.incremental\":true,\"sql.ttl.max\":\"10m\",\"failure.rate\":5,\"time.characteristic\":\"ProcessingTime\",\"env.parallelism\":1,\"checkpoint.enable\":true,\"checkpoint.timeout\":600000,\"sql.ttl.min\":\"5m\",\"checkpoint.mode\":\"EXACTLY_ONCE\",\"state.backend\":\"rocksdb\",\"checkpoint.interval\":60000,\"max.concurrent.checkpoints\":1,\"state.checkpoints.dir\":\"hdfs:///tmp\"},\"ddl\":[\"CREATE TABLE `hz_04031554`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04031554')\",\"CREATE TABLE `k2h_hypcml_hz_04031554_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04031554_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\"],\"dml\":[\"insert into k2h_hypcml_hz_04031554_table_group select * from hz_04031554\"],\"name\":\"hz_04031554\"}",
        "id": 33,
        "name": "hz_04031554",
        "owner": "1",
        "ownerName": "4pdadmin",
        "updateTime": 1585900467000,
        "workspaceId": 10
      },
      "createTime": "Fri, 03 Apr 2020 15:54:38 GMT",
      "flinkJob": {
        "config": "{\"id\":33,\"workspaceId\":10,\"owner\":\"1\",\"ownerName\":\"4pdadmin\",\"name\":\"hz_04031554\",\"flinkSql\":\"{\\\"conf\\\":{\\\"delay.interval\\\":10000,\\\"checkpoint.cleanup.mode\\\":false,\\\"failure.interval\\\":600000,\\\"state.backend.incremental\\\":true,\\\"sql.ttl.max\\\":\\\"10m\\\",\\\"failure.rate\\\":5,\\\"time.characteristic\\\":\\\"ProcessingTime\\\",\\\"env.parallelism\\\":1,\\\"checkpoint.enable\\\":true,\\\"checkpoint.timeout\\\":600000,\\\"sql.ttl.min\\\":\\\"5m\\\",\\\"checkpoint.mode\\\":\\\"EXACTLY_ONCE\\\",\\\"state.backend\\\":\\\"rocksdb\\\",\\\"checkpoint.interval\\\":60000,\\\"max.concurrent.checkpoints\\\":1,\\\"state.checkpoints.dir\\\":\\\"hdfs:///tmp\\\"},\\\"ddl\\\":[\\\"CREATE TABLE `hz_04031554`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04031554')\\\",\\\"CREATE TABLE `k2h_hypcml_hz_04031554_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04031554_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\\\"],\\\"dml\\\":[\\\"insert into k2h_hypcml_hz_04031554_table_group select * from hz_04031554\\\"],\\\"name\\\":\\\"hz_04031554\\\"}\",\"createTime\":1585900467000,\"updateTime\":1585900467000}",
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "028fa3398fe0d15c19e85bfd292849b6",
        "info": {
          "checkpoints": {
            "counts": {
              "completed": 1028,
              "failed": 0,
              "in_progress": 0,
              "restored": 1,
              "total": 1028
            },
            "history": [
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 158,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1545",
                "id": 1545,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994939016,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994938858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 150,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1544",
                "id": 1544,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994879008,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994878858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 196,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1543",
                "id": 1543,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994819054,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994818858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 143,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1542",
                "id": 1542,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994759001,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994758858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 122,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1541",
                "id": 1541,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994698980,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994698858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 198,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1540",
                "id": 1540,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994639056,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994638858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 143,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1539",
                "id": 1539,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994579001,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994578858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 214,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1538",
                "id": 1538,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994519072,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994518858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 176,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1537",
                "id": 1537,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994459034,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994458858
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 310,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1536",
                "id": 1536,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994399168,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994398858
              }
            ],
            "latest": {
              "completed": {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 158,
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-1545",
                "id": 1545,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994939016,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994938858
              },
              "failed": null,
              "restored": {
                "external_path": "hdfs:/tmp/028fa3398fe0d15c19e85bfd292849b6/chk-517",
                "id": 517,
                "is_savepoint": false,
                "restore_timestamp": 1585932318127
              },
              "savepoint": null
            },
            "summary": {
              "alignment_buffered": {
                "avg": 0,
                "max": 0,
                "min": 0
              },
              "end_to_end_duration": {
                "avg": 1769,
                "max": 341129,
                "min": 78
              },
              "state_size": {
                "avg": 1657,
                "max": 1657,
                "min": 1657
              }
            }
          },
          "exceptions": {
            "all-exceptions": [],
            "root-exception": null,
            "timestamp": null,
            "truncated": false
          },
          "main": {
            "duration": 62659567,
            "end-time": -1,
            "isStoppable": false,
            "jid": "028fa3398fe0d15c19e85bfd292849b6",
            "name": "hz_04031554",
            "now": 1585994977610,
            "plan": {
              "jid": "028fa3398fe0d15c19e85bfd292849b6",
              "name": "hz_04031554",
              "nodes": [
                {
                  "description": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -&gt; SourceConversion(table=[default_catalog.default_database.hz_04031554, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -&gt; SinkConversionToRow -&gt; Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                  "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                  "operator": "",
                  "operator_strategy": "",
                  "optimizer_properties": {},
                  "parallelism": 1
                }
              ]
            },
            "start-time": 1585932318043,
            "state": "RUNNING",
            "status-counts": {
              "CANCELED": 0,
              "CANCELING": 0,
              "CREATED": 0,
              "DEPLOYING": 0,
              "FAILED": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RUNNING": 1,
              "SCHEDULED": 0
            },
            "timestamps": {
              "CANCELED": 0,
              "CANCELLING": 0,
              "CREATED": 1585932318043,
              "FAILED": 0,
              "FAILING": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RESTARTING": 0,
              "RUNNING": 1585932318144,
              "SUSPENDED": 0
            },
            "vertices": [
              {
                "duration": 62659370,
                "end-time": -1,
                "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                "metrics": {
                  "read-bytes": 0,
                  "read-bytes-complete": true,
                  "read-records": 0,
                  "read-records-complete": true,
                  "write-bytes": 0,
                  "write-bytes-complete": true,
                  "write-records": 0,
                  "write-records-complete": true
                },
                "name": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -> SourceConversion(table=[default_catalog.default_database.hz_04031554, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -> SinkConversionToRow -> Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                "parallelism": 1,
                "start-time": 1585932318240,
                "status": "RUNNING",
                "tasks": {
                  "CANCELED": 0,
                  "CANCELING": 0,
                  "CREATED": 0,
                  "DEPLOYING": 0,
                  "FAILED": 0,
                  "FINISHED": 0,
                  "RECONCILING": 0,
                  "RUNNING": 1,
                  "SCHEDULED": 0
                }
              }
            ]
          }
        },
        "logMeta": {
          "module": "flink-jobmanager-10",
          "namespace": "prophet-resource-huangzhen",
          "query": "028fa3398fe0d15c19e85bfd292849b6"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "RUNNING",
        "trackingUrl": "/scoped-flink-cluster/10/#/job/028fa3398fe0d15c19e85bfd292849b6/overview"
      },
      "id": 12,
      "name": "hz_04031554",
      "sidecarJob": {
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "1967a922-5163-48ef-999b-250fb4277626",
        "info": {
          "hdfs-element-scanner": {
            "availableReplicas": 1,
            "calcStatus": "Online",
            "conditions": [
              {
                "lastTransitionTime": "2020-04-03 15:54:37 +0800 CST",
                "lastUpdateTime": "2020-04-03 15:54:37 +0800 CST",
                "message": "Deployment has minimum availability.",
                "reason": "MinimumReplicasAvailable",
                "status": "True",
                "type": "Available"
              }
            ],
            "podStatuses": [
              {
                "conditions": [
                  {
                    "lastProbeTime": "0001-01-01 00:00:00 +0000 UTC",
                    "lastTransitionTime": "2020-04-03 21:33:11 +0800 CST",
                    "message": "",
                    "reason": "",
                    "status": "True",
                    "type": "Initialized"
                  },
                  {
                    "lastProbeTime": "0001-01-01 00:00:00 +0000 UTC",
                    "lastTransitionTime": "2020-04-03 21:33:14 +0800 CST",
                    "message": "",
                    "reason": "",
                    "status": "True",
                    "type": "Ready"
                  },
                  {
                    "lastProbeTime": "0001-01-01 00:00:00 +0000 UTC",
                    "lastTransitionTime": "2020-04-03 21:33:08 +0800 CST",
                    "message": "",
                    "reason": "",
                    "status": "True",
                    "type": "PodScheduled"
                  }
                ],
                "containerStatuses": [
                  {
                    "containerID": "docker://ec01ceb8b73f4952bd211b58c5fcbd0d06d5e2d291306504c39092c7bff31634",
                    "image": "docker-search.4pd.io/env/feat/support-auth/prophet/app/hdfs-element-scanner.tar:pipe-43-commit-28b409e4",
                    "imageID": "docker-pullable://docker-search.4pd.io/env/feat/support-auth/prophet/app/hdfs-element-scanner.tar@sha256:8f859ec92e822a3c2657f63f2722080bc1a566c210caf9ffb7f991d8facde7e9",
                    "lastTerminationState": {
                      "running": null,
                      "terminated": null,
                      "waiting": null
                    },
                    "name": "app",
                    "ready": true,
                    "restartCount": 0,
                    "state": {
                      "running": {
                        "startedAt": "2020-04-03 21:33:12 +0800 CST"
                      },
                      "terminated": null,
                      "waiting": null
                    }
                  },
                  {
                    "containerID": "docker://5a20707cbde5b2243084dbc00cc10afc85bc1dad86afaec3bf56238c600cb23c",
                    "image": "docker-search.4pd.io/env/release/3.8.2/prophet/app/monitor-proxy.tar:pipe-66-commit-2314c3db",
                    "imageID": "docker-pullable://docker-search.4pd.io/env/release/3.8.2/prophet/app/monitor-proxy.tar@sha256:ff4ee7bbf4b49c55a563c91f4edb5ad297f6bc39e2d19fc0d19dda3d3066056f",
                    "lastTerminationState": {
                      "running": null,
                      "terminated": null,
                      "waiting": null
                    },
                    "name": "monitor-proxy",
                    "ready": true,
                    "restartCount": 0,
                    "state": {
                      "running": {
                        "startedAt": "2020-04-03 21:33:12 +0800 CST"
                      },
                      "terminated": null,
                      "waiting": null
                    }
                  }
                ],
                "hostIP": "172.27.128.145",
                "initContainerStatuses": [
                  {
                    "containerID": "docker://7d3697021d3cf89671b718e7a072cd41d74fd701df8aa0f7b00f77bdc98d3696",
                    "image": "docker-search.4pd.io/env/release/3.7.0/prophet/app/base-utils.tar:pipe-75-commit-9fcfaa33",
                    "imageID": "docker-pullable://docker-search.4pd.io/env/release/3.7.0/prophet/app/base-utils.tar@sha256:f1481e30bd49f5368e3afc874a1ba36bcff1e1bdb836d1ebbd3cc9043217a3de",
                    "lastTerminationState": {
                      "running": null,
                      "terminated": null,
                      "waiting": null
                    },
                    "name": "pas-hadoopconfigdownloader",
                    "ready": true,
                    "restartCount": 0,
                    "state": {
                      "running": null,
                      "terminated": {
                        "containerID": "docker://7d3697021d3cf89671b718e7a072cd41d74fd701df8aa0f7b00f77bdc98d3696",
                        "exitCode": 0,
                        "finishedAt": "2020-04-03 21:33:11 +0800 CST",
                        "message": "",
                        "reason": "Completed",
                        "signal": 0,
                        "startedAt": "2020-04-03 21:33:11 +0800 CST"
                      },
                      "waiting": null
                    }
                  }
                ],
                "message": "",
                "name": "pas-1967a922-5163-48ef-999b-250fb4277626-hdfs-element-scan6qw5s",
                "nominatedNodeName": "",
                "phase": "Running",
                "podIP": "10.244.72.30",
                "qOSClass": "Burstable",
                "reason": "",
                "startTime": "2020-04-03 21:33:08 +0800 CST"
              }
            ],
            "readyReplicas": 1,
            "replicas": 1,
            "unavailableReplicas": 0,
            "updatedReplicas": 1
          }
        },
        "logMeta": {
          "module": "1967a922-5163-48ef-999b-250fb4277626",
          "namespace": "prophet-resource-huangzhen"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "Online",
        "trackingUrl": "/hdfs-element-scanner/1967a922-5163-48ef-999b-250fb4277626/"
      },
      "status": "RUNNING",
      "updateTime": "Sat, 04 Apr 2020 00:15:49 GMT"
    },
    {
      "config": {
        "createTime": 1585900177000,
        "description": null,
        "entryClass": null,
        "flinkSql": "{\"conf\":{\"delay.interval\":10000,\"checkpoint.cleanup.mode\":false,\"failure.interval\":600000,\"state.backend.incremental\":true,\"sql.ttl.max\":\"10m\",\"failure.rate\":5,\"time.characteristic\":\"ProcessingTime\",\"env.parallelism\":1,\"checkpoint.enable\":true,\"checkpoint.timeout\":600000,\"sql.ttl.min\":\"5m\",\"checkpoint.mode\":\"EXACTLY_ONCE\",\"state.backend\":\"rocksdb\",\"checkpoint.interval\":60000,\"max.concurrent.checkpoints\":1,\"state.checkpoints.dir\":\"hdfs:///tmp\"},\"ddl\":[\"CREATE TABLE `hz_04031549`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04031549')\",\"CREATE TABLE `k2h_hypcml_hz_04031549_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04031549_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\"],\"dml\":[\"insert into k2h_hypcml_hz_04031549_table_group select * from hz_04031549\"],\"name\":\"hz_04031549\"}",
        "id": 32,
        "name": "hz_04031549",
        "owner": "1",
        "ownerName": "4pdadmin",
        "updateTime": 1585900177000,
        "workspaceId": 10
      },
      "createTime": "Fri, 03 Apr 2020 15:50:06 GMT",
      "flinkJob": {
        "config": "{\"id\":32,\"workspaceId\":10,\"owner\":\"1\",\"ownerName\":\"4pdadmin\",\"name\":\"hz_04031549\",\"flinkSql\":\"{\\\"conf\\\":{\\\"delay.interval\\\":10000,\\\"checkpoint.cleanup.mode\\\":false,\\\"failure.interval\\\":600000,\\\"state.backend.incremental\\\":true,\\\"sql.ttl.max\\\":\\\"10m\\\",\\\"failure.rate\\\":5,\\\"time.characteristic\\\":\\\"ProcessingTime\\\",\\\"env.parallelism\\\":1,\\\"checkpoint.enable\\\":true,\\\"checkpoint.timeout\\\":600000,\\\"sql.ttl.min\\\":\\\"5m\\\",\\\"checkpoint.mode\\\":\\\"EXACTLY_ONCE\\\",\\\"state.backend\\\":\\\"rocksdb\\\",\\\"checkpoint.interval\\\":60000,\\\"max.concurrent.checkpoints\\\":1,\\\"state.checkpoints.dir\\\":\\\"hdfs:///tmp\\\"},\\\"ddl\\\":[\\\"CREATE TABLE `hz_04031549`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04031549')\\\",\\\"CREATE TABLE `k2h_hypcml_hz_04031549_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04031549_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\\\"],\\\"dml\\\":[\\\"insert into k2h_hypcml_hz_04031549_table_group select * from hz_04031549\\\"],\\\"name\\\":\\\"hz_04031549\\\"}\",\"createTime\":1585900177000,\"updateTime\":1585900177000}",
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "fe27007a55464182936f67adf2062d96",
        "info": {
          "checkpoints": {
            "counts": {
              "completed": 1028,
              "failed": 0,
              "in_progress": 0,
              "restored": 1,
              "total": 1028
            },
            "history": [
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 148,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1549",
                "id": 1549,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994925064,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994924916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 149,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1548",
                "id": 1548,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994865065,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994864916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 194,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1547",
                "id": 1547,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994805110,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994804916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 150,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1546",
                "id": 1546,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994745066,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994744916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 138,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1545",
                "id": 1545,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994685054,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994684916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 188,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1544",
                "id": 1544,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994625104,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994624916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 185,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1543",
                "id": 1543,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994565101,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994564916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 205,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1542",
                "id": 1542,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994505121,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994504916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 160,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1541",
                "id": 1541,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994445076,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994444916
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 137,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1540",
                "id": 1540,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994385053,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994384916
              }
            ],
            "latest": {
              "completed": {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 148,
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-1549",
                "id": 1549,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585994925064,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585994924916
              },
              "failed": null,
              "restored": {
                "external_path": "hdfs:/tmp/fe27007a55464182936f67adf2062d96/chk-521",
                "id": 521,
                "is_savepoint": false,
                "restore_timestamp": 1585932320440
              },
              "savepoint": null
            },
            "summary": {
              "alignment_buffered": {
                "avg": 0,
                "max": 0,
                "min": 0
              },
              "end_to_end_duration": {
                "avg": 1486,
                "max": 322366,
                "min": 90
              },
              "state_size": {
                "avg": 1657,
                "max": 1657,
                "min": 1657
              }
            }
          },
          "exceptions": {
            "all-exceptions": [],
            "root-exception": null,
            "timestamp": null,
            "truncated": false
          },
          "main": {
            "duration": 62657374,
            "end-time": -1,
            "isStoppable": false,
            "jid": "fe27007a55464182936f67adf2062d96",
            "name": "hz_04031549",
            "now": 1585994977741,
            "plan": {
              "jid": "fe27007a55464182936f67adf2062d96",
              "name": "hz_04031549",
              "nodes": [
                {
                  "description": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -&gt; SourceConversion(table=[default_catalog.default_database.hz_04031549, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -&gt; SinkConversionToRow -&gt; Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                  "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                  "operator": "",
                  "operator_strategy": "",
                  "optimizer_properties": {},
                  "parallelism": 1
                }
              ]
            },
            "start-time": 1585932320367,
            "state": "RUNNING",
            "status-counts": {
              "CANCELED": 0,
              "CANCELING": 0,
              "CREATED": 0,
              "DEPLOYING": 0,
              "FAILED": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RUNNING": 1,
              "SCHEDULED": 0
            },
            "timestamps": {
              "CANCELED": 0,
              "CANCELLING": 0,
              "CREATED": 1585932320367,
              "FAILED": 0,
              "FAILING": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RESTARTING": 0,
              "RUNNING": 1585932320535,
              "SUSPENDED": 0
            },
            "vertices": [
              {
                "duration": 62657173,
                "end-time": -1,
                "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                "metrics": {
                  "read-bytes": 0,
                  "read-bytes-complete": true,
                  "read-records": 0,
                  "read-records-complete": true,
                  "write-bytes": 0,
                  "write-bytes-complete": true,
                  "write-records": 0,
                  "write-records-complete": true
                },
                "name": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -> SourceConversion(table=[default_catalog.default_database.hz_04031549, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -> SinkConversionToRow -> Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                "parallelism": 1,
                "start-time": 1585932320568,
                "status": "RUNNING",
                "tasks": {
                  "CANCELED": 0,
                  "CANCELING": 0,
                  "CREATED": 0,
                  "DEPLOYING": 0,
                  "FAILED": 0,
                  "FINISHED": 0,
                  "RECONCILING": 0,
                  "RUNNING": 1,
                  "SCHEDULED": 0
                }
              }
            ]
          }
        },
        "logMeta": {
          "module": "flink-jobmanager-10",
          "namespace": "prophet-resource-huangzhen",
          "query": "fe27007a55464182936f67adf2062d96"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "RUNNING",
        "trackingUrl": "/scoped-flink-cluster/10/#/job/fe27007a55464182936f67adf2062d96/overview"
      },
      "id": 11,
      "name": "hz_04031549",
      "sidecarJob": {
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "c398fd18-905a-422d-b668-82bd0f8c0bf5",
        "info": {
          "hdfs-element-scanner": {
            "availableReplicas": 1,
            "calcStatus": "Online",
            "conditions": [
              {
                "lastTransitionTime": "2020-04-03 15:50:06 +0800 CST",
                "lastUpdateTime": "2020-04-03 15:50:06 +0800 CST",
                "message": "Deployment has minimum availability.",
                "reason": "MinimumReplicasAvailable",
                "status": "True",
                "type": "Available"
              }
            ],
            "podStatuses": [
              {
                "conditions": [
                  {
                    "lastProbeTime": "0001-01-01 00:00:00 +0000 UTC",
                    "lastTransitionTime": "2020-04-03 15:50:09 +0800 CST",
                    "message": "",
                    "reason": "",
                    "status": "True",
                    "type": "Initialized"
                  },
                  {
                    "lastProbeTime": "0001-01-01 00:00:00 +0000 UTC",
                    "lastTransitionTime": "2020-04-03 15:50:12 +0800 CST",
                    "message": "",
                    "reason": "",
                    "status": "True",
                    "type": "Ready"
                  },
                  {
                    "lastProbeTime": "0001-01-01 00:00:00 +0000 UTC",
                    "lastTransitionTime": "2020-04-03 15:50:06 +0800 CST",
                    "message": "",
                    "reason": "",
                    "status": "True",
                    "type": "PodScheduled"
                  }
                ],
                "containerStatuses": [
                  {
                    "containerID": "docker://f171139929790af46b0447d8dc973b9c62b85b6cdaef396101d45dbe8ed11ae6",
                    "image": "docker-search.4pd.io/env/feat/support-auth/prophet/app/hdfs-element-scanner.tar:pipe-43-commit-28b409e4",
                    "imageID": "docker-pullable://docker-search.4pd.io/env/feat/support-auth/prophet/app/hdfs-element-scanner.tar@sha256:8f859ec92e822a3c2657f63f2722080bc1a566c210caf9ffb7f991d8facde7e9",
                    "lastTerminationState": {
                      "running": null,
                      "terminated": null,
                      "waiting": null
                    },
                    "name": "app",
                    "ready": true,
                    "restartCount": 0,
                    "state": {
                      "running": {
                        "startedAt": "2020-04-03 15:50:10 +0800 CST"
                      },
                      "terminated": null,
                      "waiting": null
                    }
                  },
                  {
                    "containerID": "docker://57167bd08ad73a2743e6acfa48738903e577b40b5d1bf84394f938364d751eca",
                    "image": "docker-search.4pd.io/env/release/3.8.2/prophet/app/monitor-proxy.tar:pipe-66-commit-2314c3db",
                    "imageID": "docker-pullable://docker-search.4pd.io/env/release/3.8.2/prophet/app/monitor-proxy.tar@sha256:ff4ee7bbf4b49c55a563c91f4edb5ad297f6bc39e2d19fc0d19dda3d3066056f",
                    "lastTerminationState": {
                      "running": null,
                      "terminated": null,
                      "waiting": null
                    },
                    "name": "monitor-proxy",
                    "ready": true,
                    "restartCount": 0,
                    "state": {
                      "running": {
                        "startedAt": "2020-04-03 15:50:10 +0800 CST"
                      },
                      "terminated": null,
                      "waiting": null
                    }
                  }
                ],
                "hostIP": "172.27.128.145",
                "initContainerStatuses": [
                  {
                    "containerID": "docker://e22a6e1989c9b376d7cf5301d97422432dbf863acd5a93db35355ea3caebebf3",
                    "image": "docker-search.4pd.io/env/release/3.7.0/prophet/app/base-utils.tar:pipe-75-commit-9fcfaa33",
                    "imageID": "docker-pullable://docker-search.4pd.io/env/release/3.7.0/prophet/app/base-utils.tar@sha256:f1481e30bd49f5368e3afc874a1ba36bcff1e1bdb836d1ebbd3cc9043217a3de",
                    "lastTerminationState": {
                      "running": null,
                      "terminated": null,
                      "waiting": null
                    },
                    "name": "pas-hadoopconfigdownloader",
                    "ready": true,
                    "restartCount": 0,
                    "state": {
                      "running": null,
                      "terminated": {
                        "containerID": "docker://e22a6e1989c9b376d7cf5301d97422432dbf863acd5a93db35355ea3caebebf3",
                        "exitCode": 0,
                        "finishedAt": "2020-04-03 15:50:09 +0800 CST",
                        "message": "",
                        "reason": "Completed",
                        "signal": 0,
                        "startedAt": "2020-04-03 15:50:08 +0800 CST"
                      },
                      "waiting": null
                    }
                  }
                ],
                "message": "",
                "name": "pas-c398fd18-905a-422d-b668-82bd0f8c0bf5-hdfs-element-scan5s542",
                "nominatedNodeName": "",
                "phase": "Running",
                "podIP": "10.244.72.25",
                "qOSClass": "Burstable",
                "reason": "",
                "startTime": "2020-04-03 15:50:06 +0800 CST"
              }
            ],
            "readyReplicas": 1,
            "replicas": 1,
            "unavailableReplicas": 0,
            "updatedReplicas": 1
          }
        },
        "logMeta": {
          "module": "c398fd18-905a-422d-b668-82bd0f8c0bf5",
          "namespace": "prophet-resource-huangzhen"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "Online",
        "trackingUrl": "/hdfs-element-scanner/c398fd18-905a-422d-b668-82bd0f8c0bf5/"
      },
      "status": "RUNNING",
      "updateTime": "Fri, 03 Apr 2020 15:50:06 GMT"
    },
    {
      "config": {
        "createTime": 1585810814000,
        "description": null,
        "entryClass": null,
        "flinkSql": "{\"conf\":{\"delay.interval\":10000,\"checkpoint.cleanup.mode\":false,\"failure.interval\":600000,\"state.backend.incremental\":true,\"sql.ttl.max\":\"10m\",\"failure.rate\":5,\"time.characteristic\":\"ProcessingTime\",\"env.parallelism\":1,\"checkpoint.enable\":true,\"checkpoint.timeout\":600000,\"sql.ttl.min\":\"5m\",\"checkpoint.mode\":\"EXACTLY_ONCE\",\"state.backend\":\"rocksdb\",\"checkpoint.interval\":60000,\"max.concurrent.checkpoints\":1,\"state.checkpoints.dir\":\"hdfs:///tmp\"},\"ddl\":[\"CREATE TABLE `hz_04021500`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04021500')\",\"CREATE TABLE `k2h_hypcml_hz_04021500_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04021500_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\"],\"dml\":[\"insert into k2h_hypcml_hz_04021500_table_group select * from hz_04021500\"],\"name\":\"hz_04021500\"}",
        "id": 15,
        "name": "hz_04021500",
        "owner": "1",
        "ownerName": "4pdadmin",
        "updateTime": 1585810814000,
        "workspaceId": 10
      },
      "createTime": "Thu, 02 Apr 2020 15:00:16 GMT",
      "flinkJob": {
        "config": "{\"id\":15,\"workspaceId\":10,\"owner\":\"1\",\"ownerName\":\"4pdadmin\",\"name\":\"hz_04021500\",\"flinkSql\":\"{\\\"conf\\\":{\\\"delay.interval\\\":10000,\\\"checkpoint.cleanup.mode\\\":false,\\\"failure.interval\\\":600000,\\\"state.backend.incremental\\\":true,\\\"sql.ttl.max\\\":\\\"10m\\\",\\\"failure.rate\\\":5,\\\"time.characteristic\\\":\\\"ProcessingTime\\\",\\\"env.parallelism\\\":1,\\\"checkpoint.enable\\\":true,\\\"checkpoint.timeout\\\":600000,\\\"sql.ttl.min\\\":\\\"5m\\\",\\\"checkpoint.mode\\\":\\\"EXACTLY_ONCE\\\",\\\"state.backend\\\":\\\"rocksdb\\\",\\\"checkpoint.interval\\\":60000,\\\"max.concurrent.checkpoints\\\":1,\\\"state.checkpoints.dir\\\":\\\"hdfs:///tmp\\\"},\\\"ddl\\\":[\\\"CREATE TABLE `hz_04021500`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04021500')\\\",\\\"CREATE TABLE `k2h_hypcml_hz_04021500_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04021500_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\\\"],\\\"dml\\\":[\\\"insert into k2h_hypcml_hz_04021500_table_group select * from hz_04021500\\\"],\\\"name\\\":\\\"hz_04021500\\\"}\",\"createTime\":1585810814000,\"updateTime\":1585810814000}",
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "d1be03232e92d4ddd921853c2cb132db",
        "info": {
          "checkpoints": {
            "counts": {
              "completed": 0,
              "failed": 0,
              "in_progress": 0,
              "restored": 5,
              "total": 0
            },
            "history": [],
            "latest": {
              "completed": null,
              "failed": null,
              "restored": {
                "external_path": "hdfs:/tmp/d1be03232e92d4ddd921853c2cb132db/chk-1396",
                "id": 1396,
                "is_savepoint": false,
                "restore_timestamp": 1585895099530
              },
              "savepoint": null
            },
            "summary": {
              "alignment_buffered": {
                "avg": 0,
                "max": 0,
                "min": 0
              },
              "end_to_end_duration": {
                "avg": 0,
                "max": 0,
                "min": 0
              },
              "state_size": {
                "avg": 0,
                "max": 0,
                "min": 0
              }
            }
          },
          "exceptions": {
            "all-exceptions": [
              {
                "exception": "java.util.concurrent.CompletionException: org.apache.flink.runtime.jobmanager.scheduler.NoResourceAvailableException: No pooled slot available and request to ResourceManager for new slot failed\n\tat java.util.concurrent.CompletableFuture.encodeThrowable(CompletableFuture.java:292)\n\tat java.util.concurrent.CompletableFuture.completeThrowable(CompletableFuture.java:308)\n\tat java.util.concurrent.CompletableFuture.uniApply(CompletableFuture.java:593)\n\tat java.util.concurrent.CompletableFuture$UniApply.tryFire(CompletableFuture.java:577)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotPoolImpl.slotRequestToResourceManagerFailed(SlotPoolImpl.java:357)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotPoolImpl.lambda$requestSlotFromResourceManager$1(SlotPoolImpl.java:345)\n\tat java.util.concurrent.CompletableFuture.uniWhenComplete(CompletableFuture.java:760)\n\tat java.util.concurrent.CompletableFuture$UniWhenComplete.tryFire(CompletableFuture.java:736)\n\tat java.util.concurrent.CompletableFuture$Completion.run(CompletableFuture.java:442)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRunAsync(AkkaRpcActor.java:397)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcMessage(AkkaRpcActor.java:190)\n\tat org.apache.flink.runtime.rpc.akka.FencedAkkaRpcActor.handleRpcMessage(FencedAkkaRpcActor.java:74)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleMessage(AkkaRpcActor.java:152)\n\tat akka.japi.pf.UnitCaseStatement.apply(CaseStatements.scala:26)\n\tat akka.japi.pf.UnitCaseStatement.apply(CaseStatements.scala:21)\n\tat scala.PartialFunction$class.applyOrElse(PartialFunction.scala:123)\n\tat akka.japi.pf.UnitCaseStatement.applyOrElse(CaseStatements.scala:21)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:170)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:171)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:171)\n\tat akka.actor.Actor$class.aroundReceive(Actor.scala:517)\n\tat akka.actor.AbstractActor.aroundReceive(AbstractActor.scala:225)\n\tat akka.actor.ActorCell.receiveMessage(ActorCell.scala:592)\n\tat akka.actor.ActorCell.invoke(ActorCell.scala:561)\n\tat akka.dispatch.Mailbox.processMailbox(Mailbox.scala:258)\n\tat akka.dispatch.Mailbox.run(Mailbox.scala:225)\n\tat akka.dispatch.Mailbox.exec(Mailbox.scala:235)\n\tat akka.dispatch.forkjoin.ForkJoinTask.doExec(ForkJoinTask.java:260)\n\tat akka.dispatch.forkjoin.ForkJoinPool$WorkQueue.runTask(ForkJoinPool.java:1339)\n\tat akka.dispatch.forkjoin.ForkJoinPool.runWorker(ForkJoinPool.java:1979)\n\tat akka.dispatch.forkjoin.ForkJoinWorkerThread.run(ForkJoinWorkerThread.java:107)\nCaused by: org.apache.flink.runtime.jobmanager.scheduler.NoResourceAvailableException: No pooled slot available and request to ResourceManager for new slot failed\n\t... 27 more\nCaused by: java.util.concurrent.CompletionException: io.fabric8.kubernetes.client.KubernetesClientException: Failure executing: POST at: https://10.42.0.1/api/v1/namespaces/prophet-resource-huangzhen/pods. Message: Forbidden!Configured service account doesn't have access. Service account may have been revoked. pods \"flink-jobmanager-10-taskmanager-1-5\" is forbidden: exceeded quota: init, requested: limits.memory=10Gi, used: limits.memory=95208Mi, limited: limits.memory=100G.\n\tat java.util.concurrent.CompletableFuture.encodeThrowable(CompletableFuture.java:292)\n\tat java.util.concurrent.CompletableFuture.completeThrowable(CompletableFuture.java:308)\n\tat java.util.concurrent.CompletableFuture.uniApply(CompletableFuture.java:593)\n\tat java.util.concurrent.CompletableFuture$UniApply.tryFire(CompletableFuture.java:577)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.concurrent.FutureUtils$1.onComplete(FutureUtils.java:872)\n\tat akka.dispatch.OnComplete.internal(Future.scala:263)\n\tat akka.dispatch.OnComplete.internal(Future.scala:261)\n\tat akka.dispatch.japi$CallbackBridge.apply(Future.scala:191)\n\tat akka.dispatch.japi$CallbackBridge.apply(Future.scala:188)\n\tat scala.concurrent.impl.CallbackRunnable.run(Promise.scala:36)\n\tat org.apache.flink.runtime.concurrent.Executors$DirectExecutionContext.execute(Executors.java:74)\n\tat scala.concurrent.impl.CallbackRunnable.executeWithValue(Promise.scala:44)\n\tat scala.concurrent.impl.Promise$DefaultPromise.tryComplete(Promise.scala:252)\n\tat akka.pattern.PromiseActorRef.$bang(AskSupport.scala:572)\n\tat akka.actor.ActorRef.tell(ActorRef.scala:126)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcInvocation(AkkaRpcActor.java:285)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcMessage(AkkaRpcActor.java:194)\n\t... 20 more\nCaused by: io.fabric8.kubernetes.client.KubernetesClientException: Failure executing: POST at: https://10.42.0.1/api/v1/namespaces/prophet-resource-huangzhen/pods. Message: Forbidden!Configured service account doesn't have access. Service account may have been revoked. pods \"flink-jobmanager-10-taskmanager-1-5\" is forbidden: exceeded quota: init, requested: limits.memory=10Gi, used: limits.memory=95208Mi, limited: limits.memory=100G.\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.requestFailure(OperationSupport.java:510)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.assertResponseCode(OperationSupport.java:447)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleResponse(OperationSupport.java:413)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleResponse(OperationSupport.java:372)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleCreate(OperationSupport.java:241)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.handleCreate(BaseOperation.java:798)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.create(BaseOperation.java:328)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.create(BaseOperation.java:324)\n\tat org.apache.flink.kubernetes.kubeclient.Fabric8FlinkKubeClient.createTaskManagerPod(Fabric8FlinkKubeClient.java:172)\n\tat org.apache.flink.kubernetes.KubernetesResourceManager.requestKubernetesPod(KubernetesResourceManager.java:273)\n\tat org.apache.flink.kubernetes.KubernetesResourceManager.startNewWorker(KubernetesResourceManager.java:173)\n\tat org.apache.flink.runtime.resourcemanager.ResourceManager$ResourceActionsImpl.allocateResource(ResourceManager.java:1074)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.allocateResource(SlotManagerImpl.java:797)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.fulfillPendingSlotRequestWithPendingTaskManagerSlot(SlotManagerImpl.java:763)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.lambda$internalRequestSlot$7(SlotManagerImpl.java:755)\n\tat org.apache.flink.util.OptionalConsumer.ifNotPresent(OptionalConsumer.java:52)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.internalRequestSlot(SlotManagerImpl.java:755)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.registerSlotRequest(SlotManagerImpl.java:314)\n\tat org.apache.flink.runtime.resourcemanager.ResourceManager.requestSlot(ResourceManager.java:431)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)\n\tat sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)\n\tat java.lang.reflect.Method.invoke(Method.java:498)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcInvocation(AkkaRpcActor.java:279)\n\t... 21 more\n",
                "location": "(unassigned)",
                "task": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -> SourceConversion(table=[default_catalog.default_database.hz_04021500, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -> SinkConversionToRow -> Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime) (1/1)",
                "timestamp": 1585895099547
              }
            ],
            "root-exception": "org.apache.flink.runtime.JobException: Recovery is suppressed by FailureRateRestartBackoffTimeStrategy(FailureRateRestartBackoffTimeStrategy(failuresIntervalMS=600000,backoffTimeMS=10000,maxFailuresPerInterval=5)\n\tat org.apache.flink.runtime.executiongraph.failover.flip1.ExecutionFailureHandler.handleFailure(ExecutionFailureHandler.java:110)\n\tat org.apache.flink.runtime.executiongraph.failover.flip1.ExecutionFailureHandler.getFailureHandlingResult(ExecutionFailureHandler.java:76)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.handleTaskFailure(DefaultScheduler.java:192)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.maybeHandleTaskFailure(DefaultScheduler.java:186)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.updateTaskExecutionStateInternal(DefaultScheduler.java:180)\n\tat org.apache.flink.runtime.scheduler.SchedulerBase.updateTaskExecutionState(SchedulerBase.java:484)\n\tat org.apache.flink.runtime.scheduler.UpdateSchedulerNgOnInternalFailuresListener.notifyTaskFailure(UpdateSchedulerNgOnInternalFailuresListener.java:49)\n\tat org.apache.flink.runtime.executiongraph.ExecutionGraph.notifySchedulerNgAboutInternalTaskFailure(ExecutionGraph.java:1703)\n\tat org.apache.flink.runtime.executiongraph.Execution.processFail(Execution.java:1252)\n\tat org.apache.flink.runtime.executiongraph.Execution.processFail(Execution.java:1220)\n\tat org.apache.flink.runtime.executiongraph.Execution.markFailed(Execution.java:1051)\n\tat org.apache.flink.runtime.executiongraph.ExecutionVertex.markFailed(ExecutionVertex.java:748)\n\tat org.apache.flink.runtime.scheduler.DefaultExecutionVertexOperations.markFailed(DefaultExecutionVertexOperations.java:41)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.handleTaskDeploymentFailure(DefaultScheduler.java:446)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.lambda$assignResourceOrHandleError$5(DefaultScheduler.java:433)\n\tat java.util.concurrent.CompletableFuture.uniHandle(CompletableFuture.java:822)\n\tat java.util.concurrent.CompletableFuture$UniHandle.tryFire(CompletableFuture.java:797)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SchedulerImpl.lambda$internalAllocateSlot$0(SchedulerImpl.java:168)\n\tat java.util.concurrent.CompletableFuture.uniWhenComplete(CompletableFuture.java:760)\n\tat java.util.concurrent.CompletableFuture$UniWhenComplete.tryFire(CompletableFuture.java:736)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotSharingManager$SingleTaskSlot.release(SlotSharingManager.java:726)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotSharingManager$MultiTaskSlot.release(SlotSharingManager.java:537)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotSharingManager$MultiTaskSlot.lambda$new$0(SlotSharingManager.java:432)\n\tat java.util.concurrent.CompletableFuture.uniHandle(CompletableFuture.java:822)\n\tat java.util.concurrent.CompletableFuture$UniHandle.tryFire(CompletableFuture.java:797)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.concurrent.FutureUtils.lambda$forward$21(FutureUtils.java:1065)\n\tat java.util.concurrent.CompletableFuture.uniWhenComplete(CompletableFuture.java:760)\n\tat java.util.concurrent.CompletableFuture$UniWhenComplete.tryFire(CompletableFuture.java:736)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotPoolImpl.slotRequestToResourceManagerFailed(SlotPoolImpl.java:357)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotPoolImpl.lambda$requestSlotFromResourceManager$1(SlotPoolImpl.java:345)\n\tat java.util.concurrent.CompletableFuture.uniWhenComplete(CompletableFuture.java:760)\n\tat java.util.concurrent.CompletableFuture$UniWhenComplete.tryFire(CompletableFuture.java:736)\n\tat java.util.concurrent.CompletableFuture$Completion.run(CompletableFuture.java:442)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRunAsync(AkkaRpcActor.java:397)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcMessage(AkkaRpcActor.java:190)\n\tat org.apache.flink.runtime.rpc.akka.FencedAkkaRpcActor.handleRpcMessage(FencedAkkaRpcActor.java:74)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleMessage(AkkaRpcActor.java:152)\n\tat akka.japi.pf.UnitCaseStatement.apply(CaseStatements.scala:26)\n\tat akka.japi.pf.UnitCaseStatement.apply(CaseStatements.scala:21)\n\tat scala.PartialFunction$class.applyOrElse(PartialFunction.scala:123)\n\tat akka.japi.pf.UnitCaseStatement.applyOrElse(CaseStatements.scala:21)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:170)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:171)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:171)\n\tat akka.actor.Actor$class.aroundReceive(Actor.scala:517)\n\tat akka.actor.AbstractActor.aroundReceive(AbstractActor.scala:225)\n\tat akka.actor.ActorCell.receiveMessage(ActorCell.scala:592)\n\tat akka.actor.ActorCell.invoke(ActorCell.scala:561)\n\tat akka.dispatch.Mailbox.processMailbox(Mailbox.scala:258)\n\tat akka.dispatch.Mailbox.run(Mailbox.scala:225)\n\tat akka.dispatch.Mailbox.exec(Mailbox.scala:235)\n\tat akka.dispatch.forkjoin.ForkJoinTask.doExec(ForkJoinTask.java:260)\n\tat akka.dispatch.forkjoin.ForkJoinPool$WorkQueue.runTask(ForkJoinPool.java:1339)\n\tat akka.dispatch.forkjoin.ForkJoinPool.runWorker(ForkJoinPool.java:1979)\n\tat akka.dispatch.forkjoin.ForkJoinWorkerThread.run(ForkJoinWorkerThread.java:107)\nCaused by: java.util.concurrent.CompletionException: org.apache.flink.runtime.jobmanager.scheduler.NoResourceAvailableException: No pooled slot available and request to ResourceManager for new slot failed\n\tat java.util.concurrent.CompletableFuture.encodeThrowable(CompletableFuture.java:292)\n\tat java.util.concurrent.CompletableFuture.completeThrowable(CompletableFuture.java:308)\n\tat java.util.concurrent.CompletableFuture.uniApply(CompletableFuture.java:593)\n\tat java.util.concurrent.CompletableFuture$UniApply.tryFire(CompletableFuture.java:577)\n\t... 29 more\nCaused by: org.apache.flink.runtime.jobmanager.scheduler.NoResourceAvailableException: No pooled slot available and request to ResourceManager for new slot failed\n\t... 27 more\nCaused by: java.util.concurrent.CompletionException: io.fabric8.kubernetes.client.KubernetesClientException: Failure executing: POST at: https://10.42.0.1/api/v1/namespaces/prophet-resource-huangzhen/pods. Message: Forbidden!Configured service account doesn't have access. Service account may have been revoked. pods \"flink-jobmanager-10-taskmanager-1-5\" is forbidden: exceeded quota: init, requested: limits.memory=10Gi, used: limits.memory=95208Mi, limited: limits.memory=100G.\n\tat java.util.concurrent.CompletableFuture.encodeThrowable(CompletableFuture.java:292)\n\tat java.util.concurrent.CompletableFuture.completeThrowable(CompletableFuture.java:308)\n\tat java.util.concurrent.CompletableFuture.uniApply(CompletableFuture.java:593)\n\tat java.util.concurrent.CompletableFuture$UniApply.tryFire(CompletableFuture.java:577)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.concurrent.FutureUtils$1.onComplete(FutureUtils.java:872)\n\tat akka.dispatch.OnComplete.internal(Future.scala:263)\n\tat akka.dispatch.OnComplete.internal(Future.scala:261)\n\tat akka.dispatch.japi$CallbackBridge.apply(Future.scala:191)\n\tat akka.dispatch.japi$CallbackBridge.apply(Future.scala:188)\n\tat scala.concurrent.impl.CallbackRunnable.run(Promise.scala:36)\n\tat org.apache.flink.runtime.concurrent.Executors$DirectExecutionContext.execute(Executors.java:74)\n\tat scala.concurrent.impl.CallbackRunnable.executeWithValue(Promise.scala:44)\n\tat scala.concurrent.impl.Promise$DefaultPromise.tryComplete(Promise.scala:252)\n\tat akka.pattern.PromiseActorRef.$bang(AskSupport.scala:572)\n\tat akka.actor.ActorRef.tell(ActorRef.scala:126)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcInvocation(AkkaRpcActor.java:285)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcMessage(AkkaRpcActor.java:194)\n\t... 20 more\nCaused by: io.fabric8.kubernetes.client.KubernetesClientException: Failure executing: POST at: https://10.42.0.1/api/v1/namespaces/prophet-resource-huangzhen/pods. Message: Forbidden!Configured service account doesn't have access. Service account may have been revoked. pods \"flink-jobmanager-10-taskmanager-1-5\" is forbidden: exceeded quota: init, requested: limits.memory=10Gi, used: limits.memory=95208Mi, limited: limits.memory=100G.\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.requestFailure(OperationSupport.java:510)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.assertResponseCode(OperationSupport.java:447)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleResponse(OperationSupport.java:413)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleResponse(OperationSupport.java:372)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleCreate(OperationSupport.java:241)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.handleCreate(BaseOperation.java:798)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.create(BaseOperation.java:328)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.create(BaseOperation.java:324)\n\tat org.apache.flink.kubernetes.kubeclient.Fabric8FlinkKubeClient.createTaskManagerPod(Fabric8FlinkKubeClient.java:172)\n\tat org.apache.flink.kubernetes.KubernetesResourceManager.requestKubernetesPod(KubernetesResourceManager.java:273)\n\tat org.apache.flink.kubernetes.KubernetesResourceManager.startNewWorker(KubernetesResourceManager.java:173)\n\tat org.apache.flink.runtime.resourcemanager.ResourceManager$ResourceActionsImpl.allocateResource(ResourceManager.java:1074)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.allocateResource(SlotManagerImpl.java:797)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.fulfillPendingSlotRequestWithPendingTaskManagerSlot(SlotManagerImpl.java:763)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.lambda$internalRequestSlot$7(SlotManagerImpl.java:755)\n\tat org.apache.flink.util.OptionalConsumer.ifNotPresent(OptionalConsumer.java:52)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.internalRequestSlot(SlotManagerImpl.java:755)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.registerSlotRequest(SlotManagerImpl.java:314)\n\tat org.apache.flink.runtime.resourcemanager.ResourceManager.requestSlot(ResourceManager.java:431)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)\n\tat sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)\n\tat java.lang.reflect.Method.invoke(Method.java:498)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcInvocation(AkkaRpcActor.java:279)\n\t... 21 more\n",
            "timestamp": 1585895099555,
            "truncated": false
          },
          "main": {
            "duration": 42113,
            "end-time": 1585895099560,
            "isStoppable": false,
            "jid": "d1be03232e92d4ddd921853c2cb132db",
            "name": "hz_04021500",
            "now": 1585895100037,
            "plan": {
              "jid": "d1be03232e92d4ddd921853c2cb132db",
              "name": "hz_04021500",
              "nodes": [
                {
                  "description": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -&gt; SourceConversion(table=[default_catalog.default_database.hz_04021500, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -&gt; SinkConversionToRow -&gt; Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                  "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                  "operator": "",
                  "operator_strategy": "",
                  "optimizer_properties": {},
                  "parallelism": 1
                }
              ]
            },
            "start-time": 1585895057447,
            "state": "FAILED",
            "status-counts": {
              "CANCELED": 0,
              "CANCELING": 0,
              "CREATED": 0,
              "DEPLOYING": 0,
              "FAILED": 1,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RUNNING": 0,
              "SCHEDULED": 0
            },
            "timestamps": {
              "CANCELED": 0,
              "CANCELLING": 0,
              "CREATED": 1585895057447,
              "FAILED": 1585895099560,
              "FAILING": 1585895099552,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RESTARTING": 1585895089495,
              "RUNNING": 1585895099496,
              "SUSPENDED": 0
            },
            "vertices": [
              {
                "duration": -1,
                "end-time": -1,
                "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                "metrics": {
                  "read-bytes": 0,
                  "read-bytes-complete": true,
                  "read-records": 0,
                  "read-records-complete": true,
                  "write-bytes": 0,
                  "write-bytes-complete": true,
                  "write-records": 0,
                  "write-records-complete": true
                },
                "name": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -> SourceConversion(table=[default_catalog.default_database.hz_04021500, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -> SinkConversionToRow -> Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                "parallelism": 1,
                "start-time": -1,
                "status": "FAILED",
                "tasks": {
                  "CANCELED": 0,
                  "CANCELING": 0,
                  "CREATED": 0,
                  "DEPLOYING": 0,
                  "FAILED": 1,
                  "FINISHED": 0,
                  "RECONCILING": 0,
                  "RUNNING": 0,
                  "SCHEDULED": 0
                }
              }
            ]
          }
        },
        "logMeta": {
          "module": "flink-jobmanager-10",
          "namespace": "prophet-resource-huangzhen",
          "query": "d1be03232e92d4ddd921853c2cb132db"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": "org.apache.flink.runtime.JobException: Recovery is suppressed by FailureRateRestartBackoffTimeStrategy(FailureRateRestartBackoffTimeStrategy(failuresIntervalMS=600000,backoffTimeMS=10000,maxFailuresPerInterval=5)\n\tat org.apache.flink.runtime.executiongraph.failover.flip1.ExecutionFailureHandler.handleFailure(ExecutionFailureHandler.java:110)\n\tat org.apache.flink.runtime.executiongraph.failover.flip1.ExecutionFailureHandler.getFailureHandlingResult(ExecutionFailureHandler.java:76)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.handleTaskFailure(DefaultScheduler.java:192)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.maybeHandleTaskFailure(DefaultScheduler.java:186)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.updateTaskExecutionStateInternal(DefaultScheduler.java:180)\n\tat org.apache.flink.runtime.scheduler.SchedulerBase.updateTaskExecutionState(SchedulerBase.java:484)\n\tat org.apache.flink.runtime.scheduler.UpdateSchedulerNgOnInternalFailuresListener.notifyTaskFailure(UpdateSchedulerNgOnInternalFailuresListener.java:49)\n\tat org.apache.flink.runtime.executiongraph.ExecutionGraph.notifySchedulerNgAboutInternalTaskFailure(ExecutionGraph.java:1703)\n\tat org.apache.flink.runtime.executiongraph.Execution.processFail(Execution.java:1252)\n\tat org.apache.flink.runtime.executiongraph.Execution.processFail(Execution.java:1220)\n\tat org.apache.flink.runtime.executiongraph.Execution.markFailed(Execution.java:1051)\n\tat org.apache.flink.runtime.executiongraph.ExecutionVertex.markFailed(ExecutionVertex.java:748)\n\tat org.apache.flink.runtime.scheduler.DefaultExecutionVertexOperations.markFailed(DefaultExecutionVertexOperations.java:41)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.handleTaskDeploymentFailure(DefaultScheduler.java:446)\n\tat org.apache.flink.runtime.scheduler.DefaultScheduler.lambda$assignResourceOrHandleError$5(DefaultScheduler.java:433)\n\tat java.util.concurrent.CompletableFuture.uniHandle(CompletableFuture.java:822)\n\tat java.util.concurrent.CompletableFuture$UniHandle.tryFire(CompletableFuture.java:797)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SchedulerImpl.lambda$internalAllocateSlot$0(SchedulerImpl.java:168)\n\tat java.util.concurrent.CompletableFuture.uniWhenComplete(CompletableFuture.java:760)\n\tat java.util.concurrent.CompletableFuture$UniWhenComplete.tryFire(CompletableFuture.java:736)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotSharingManager$SingleTaskSlot.release(SlotSharingManager.java:726)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotSharingManager$MultiTaskSlot.release(SlotSharingManager.java:537)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotSharingManager$MultiTaskSlot.lambda$new$0(SlotSharingManager.java:432)\n\tat java.util.concurrent.CompletableFuture.uniHandle(CompletableFuture.java:822)\n\tat java.util.concurrent.CompletableFuture$UniHandle.tryFire(CompletableFuture.java:797)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.concurrent.FutureUtils.lambda$forward$21(FutureUtils.java:1065)\n\tat java.util.concurrent.CompletableFuture.uniWhenComplete(CompletableFuture.java:760)\n\tat java.util.concurrent.CompletableFuture$UniWhenComplete.tryFire(CompletableFuture.java:736)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotPoolImpl.slotRequestToResourceManagerFailed(SlotPoolImpl.java:357)\n\tat org.apache.flink.runtime.jobmaster.slotpool.SlotPoolImpl.lambda$requestSlotFromResourceManager$1(SlotPoolImpl.java:345)\n\tat java.util.concurrent.CompletableFuture.uniWhenComplete(CompletableFuture.java:760)\n\tat java.util.concurrent.CompletableFuture$UniWhenComplete.tryFire(CompletableFuture.java:736)\n\tat java.util.concurrent.CompletableFuture$Completion.run(CompletableFuture.java:442)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRunAsync(AkkaRpcActor.java:397)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcMessage(AkkaRpcActor.java:190)\n\tat org.apache.flink.runtime.rpc.akka.FencedAkkaRpcActor.handleRpcMessage(FencedAkkaRpcActor.java:74)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleMessage(AkkaRpcActor.java:152)\n\tat akka.japi.pf.UnitCaseStatement.apply(CaseStatements.scala:26)\n\tat akka.japi.pf.UnitCaseStatement.apply(CaseStatements.scala:21)\n\tat scala.PartialFunction$class.applyOrElse(PartialFunction.scala:123)\n\tat akka.japi.pf.UnitCaseStatement.applyOrElse(CaseStatements.scala:21)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:170)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:171)\n\tat scala.PartialFunction$OrElse.applyOrElse(PartialFunction.scala:171)\n\tat akka.actor.Actor$class.aroundReceive(Actor.scala:517)\n\tat akka.actor.AbstractActor.aroundReceive(AbstractActor.scala:225)\n\tat akka.actor.ActorCell.receiveMessage(ActorCell.scala:592)\n\tat akka.actor.ActorCell.invoke(ActorCell.scala:561)\n\tat akka.dispatch.Mailbox.processMailbox(Mailbox.scala:258)\n\tat akka.dispatch.Mailbox.run(Mailbox.scala:225)\n\tat akka.dispatch.Mailbox.exec(Mailbox.scala:235)\n\tat akka.dispatch.forkjoin.ForkJoinTask.doExec(ForkJoinTask.java:260)\n\tat akka.dispatch.forkjoin.ForkJoinPool$WorkQueue.runTask(ForkJoinPool.java:1339)\n\tat akka.dispatch.forkjoin.ForkJoinPool.runWorker(ForkJoinPool.java:1979)\n\tat akka.dispatch.forkjoin.ForkJoinWorkerThread.run(ForkJoinWorkerThread.java:107)\nCaused by: java.util.concurrent.CompletionException: org.apache.flink.runtime.jobmanager.scheduler.NoResourceAvailableException: No pooled slot available and request to ResourceManager for new slot failed\n\tat java.util.concurrent.CompletableFuture.encodeThrowable(CompletableFuture.java:292)\n\tat java.util.concurrent.CompletableFuture.completeThrowable(CompletableFuture.java:308)\n\tat java.util.concurrent.CompletableFuture.uniApply(CompletableFuture.java:593)\n\tat java.util.concurrent.CompletableFuture$UniApply.tryFire(CompletableFuture.java:577)\n\t... 29 more\nCaused by: org.apache.flink.runtime.jobmanager.scheduler.NoResourceAvailableException: No pooled slot available and request to ResourceManager for new slot failed\n\t... 27 more\nCaused by: java.util.concurrent.CompletionException: io.fabric8.kubernetes.client.KubernetesClientException: Failure executing: POST at: https://10.42.0.1/api/v1/namespaces/prophet-resource-huangzhen/pods. Message: Forbidden!Configured service account doesn't have access. Service account may have been revoked. pods \"flink-jobmanager-10-taskmanager-1-5\" is forbidden: exceeded quota: init, requested: limits.memory=10Gi, used: limits.memory=95208Mi, limited: limits.memory=100G.\n\tat java.util.concurrent.CompletableFuture.encodeThrowable(CompletableFuture.java:292)\n\tat java.util.concurrent.CompletableFuture.completeThrowable(CompletableFuture.java:308)\n\tat java.util.concurrent.CompletableFuture.uniApply(CompletableFuture.java:593)\n\tat java.util.concurrent.CompletableFuture$UniApply.tryFire(CompletableFuture.java:577)\n\tat java.util.concurrent.CompletableFuture.postComplete(CompletableFuture.java:474)\n\tat java.util.concurrent.CompletableFuture.completeExceptionally(CompletableFuture.java:1977)\n\tat org.apache.flink.runtime.concurrent.FutureUtils$1.onComplete(FutureUtils.java:872)\n\tat akka.dispatch.OnComplete.internal(Future.scala:263)\n\tat akka.dispatch.OnComplete.internal(Future.scala:261)\n\tat akka.dispatch.japi$CallbackBridge.apply(Future.scala:191)\n\tat akka.dispatch.japi$CallbackBridge.apply(Future.scala:188)\n\tat scala.concurrent.impl.CallbackRunnable.run(Promise.scala:36)\n\tat org.apache.flink.runtime.concurrent.Executors$DirectExecutionContext.execute(Executors.java:74)\n\tat scala.concurrent.impl.CallbackRunnable.executeWithValue(Promise.scala:44)\n\tat scala.concurrent.impl.Promise$DefaultPromise.tryComplete(Promise.scala:252)\n\tat akka.pattern.PromiseActorRef.$bang(AskSupport.scala:572)\n\tat akka.actor.ActorRef.tell(ActorRef.scala:126)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcInvocation(AkkaRpcActor.java:285)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcMessage(AkkaRpcActor.java:194)\n\t... 20 more\nCaused by: io.fabric8.kubernetes.client.KubernetesClientException: Failure executing: POST at: https://10.42.0.1/api/v1/namespaces/prophet-resource-huangzhen/pods. Message: Forbidden!Configured service account doesn't have access. Service account may have been revoked. pods \"flink-jobmanager-10-taskmanager-1-5\" is forbidden: exceeded quota: init, requested: limits.memory=10Gi, used: limits.memory=95208Mi, limited: limits.memory=100G.\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.requestFailure(OperationSupport.java:510)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.assertResponseCode(OperationSupport.java:447)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleResponse(OperationSupport.java:413)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleResponse(OperationSupport.java:372)\n\tat io.fabric8.kubernetes.client.dsl.base.OperationSupport.handleCreate(OperationSupport.java:241)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.handleCreate(BaseOperation.java:798)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.create(BaseOperation.java:328)\n\tat io.fabric8.kubernetes.client.dsl.base.BaseOperation.create(BaseOperation.java:324)\n\tat org.apache.flink.kubernetes.kubeclient.Fabric8FlinkKubeClient.createTaskManagerPod(Fabric8FlinkKubeClient.java:172)\n\tat org.apache.flink.kubernetes.KubernetesResourceManager.requestKubernetesPod(KubernetesResourceManager.java:273)\n\tat org.apache.flink.kubernetes.KubernetesResourceManager.startNewWorker(KubernetesResourceManager.java:173)\n\tat org.apache.flink.runtime.resourcemanager.ResourceManager$ResourceActionsImpl.allocateResource(ResourceManager.java:1074)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.allocateResource(SlotManagerImpl.java:797)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.fulfillPendingSlotRequestWithPendingTaskManagerSlot(SlotManagerImpl.java:763)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.lambda$internalRequestSlot$7(SlotManagerImpl.java:755)\n\tat org.apache.flink.util.OptionalConsumer.ifNotPresent(OptionalConsumer.java:52)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.internalRequestSlot(SlotManagerImpl.java:755)\n\tat org.apache.flink.runtime.resourcemanager.slotmanager.SlotManagerImpl.registerSlotRequest(SlotManagerImpl.java:314)\n\tat org.apache.flink.runtime.resourcemanager.ResourceManager.requestSlot(ResourceManager.java:431)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)\n\tat sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)\n\tat java.lang.reflect.Method.invoke(Method.java:498)\n\tat org.apache.flink.runtime.rpc.akka.AkkaRpcActor.handleRpcInvocation(AkkaRpcActor.java:279)\n\t... 21 more\n",
        "status": "FAILED",
        "trackingUrl": "/scoped-flink-cluster/10/history/#/job/d1be03232e92d4ddd921853c2cb132db/overview"
      },
      "id": 9,
      "name": "hz_04021500",
      "sidecarJob": {
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "1fdf6996-3f79-4cf1-8a29-32b3f9d3eff4",
        "info": null,
        "logMeta": {
          "module": "1fdf6996-3f79-4cf1-8a29-32b3f9d3eff4",
          "namespace": "prophet-resource-huangzhen"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "Lost",
        "trackingUrl": "/hdfs-element-scanner/1fdf6996-3f79-4cf1-8a29-32b3f9d3eff4/"
      },
      "status": "RUNNING",
      "updateTime": "Thu, 02 Apr 2020 15:00:16 GMT"
    },
    {
      "config": {
        "createTime": 1585740882000,
        "description": null,
        "entryClass": null,
        "flinkSql": "{\"conf\":{\"delay.interval\":10000,\"checkpoint.cleanup.mode\":false,\"failure.interval\":600000,\"state.backend.incremental\":true,\"sql.ttl.max\":\"10m\",\"failure.rate\":5,\"time.characteristic\":\"ProcessingTime\",\"env.parallelism\":1,\"checkpoint.enable\":true,\"checkpoint.timeout\":600000,\"sql.ttl.min\":\"5m\",\"checkpoint.mode\":\"EXACTLY_ONCE\",\"state.backend\":\"rocksdb\",\"checkpoint.interval\":60000,\"max.concurrent.checkpoints\":1,\"state.checkpoints.dir\":\"hdfs:///tmp\"},\"ddl\":[\"CREATE TABLE `hz_04011934`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04011934')\",\"CREATE TABLE `k2h_hypcml_hz_04011934_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04011934_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\"],\"dml\":[\"insert into k2h_hypcml_hz_04011934_table_group select * from hz_04011934\"],\"name\":\"hz_04011934\"}",
        "id": 10,
        "name": "hz_04011934",
        "owner": "1",
        "ownerName": "4pdadmin",
        "updateTime": 1585740882000,
        "workspaceId": 10
      },
      "createTime": "Wed, 01 Apr 2020 19:34:45 GMT",
      "flinkJob": {
        "config": "{\"id\":10,\"workspaceId\":10,\"owner\":\"1\",\"ownerName\":\"4pdadmin\",\"name\":\"hz_04011934\",\"flinkSql\":\"{\\\"conf\\\":{\\\"delay.interval\\\":10000,\\\"checkpoint.cleanup.mode\\\":false,\\\"failure.interval\\\":600000,\\\"state.backend.incremental\\\":true,\\\"sql.ttl.max\\\":\\\"10m\\\",\\\"failure.rate\\\":5,\\\"time.characteristic\\\":\\\"ProcessingTime\\\",\\\"env.parallelism\\\":1,\\\"checkpoint.enable\\\":true,\\\"checkpoint.timeout\\\":600000,\\\"sql.ttl.min\\\":\\\"5m\\\",\\\"checkpoint.mode\\\":\\\"EXACTLY_ONCE\\\",\\\"state.backend\\\":\\\"rocksdb\\\",\\\"checkpoint.interval\\\":60000,\\\"max.concurrent.checkpoints\\\":1,\\\"state.checkpoints.dir\\\":\\\"hdfs:///tmp\\\"},\\\"ddl\\\":[\\\"CREATE TABLE `hz_04011934`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04011934')\\\",\\\"CREATE TABLE `k2h_hypcml_hz_04011934_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04011934_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\\\"],\\\"dml\\\":[\\\"insert into k2h_hypcml_hz_04011934_table_group select * from hz_04011934\\\"],\\\"name\\\":\\\"hz_04011934\\\"}\",\"createTime\":1585740882000,\"updateTime\":1585740882000}",
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "f140b14e6b02e6538ebadd8bbb55d21b",
        "info": {
          "checkpoints": {
            "counts": {
              "completed": 10,
              "failed": 0,
              "in_progress": 0,
              "restored": 0,
              "total": 10
            },
            "history": [
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 186,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-10",
                "id": 10,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741478621,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741478435
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 146,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-9",
                "id": 9,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741418581,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741418435
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 159,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-8",
                "id": 8,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741358594,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741358435
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 228,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-7",
                "id": 7,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741298663,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741298435
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 137,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-6",
                "id": 6,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741238576,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741238439
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 244,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-5",
                "id": 5,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741178679,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741178435
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 207,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-4",
                "id": 4,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741118643,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741118436
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 10300,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-3",
                "id": 3,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741068735,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741058435
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 149,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-2",
                "id": 2,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585740998584,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585740998435
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 193,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-1",
                "id": 1,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585740938628,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585740938435
              }
            ],
            "latest": {
              "completed": {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 186,
                "external_path": "hdfs:/tmp/f140b14e6b02e6538ebadd8bbb55d21b/chk-10",
                "id": 10,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585741478621,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585741478435
              },
              "failed": null,
              "restored": null,
              "savepoint": null
            },
            "summary": {
              "alignment_buffered": {
                "avg": 0,
                "max": 0,
                "min": 0
              },
              "end_to_end_duration": {
                "avg": 1194,
                "max": 10300,
                "min": 137
              },
              "state_size": {
                "avg": 1657,
                "max": 1657,
                "min": 1657
              }
            }
          },
          "exceptions": {
            "all-exceptions": [],
            "root-exception": null,
            "timestamp": null,
            "truncated": false
          },
          "main": {
            "duration": 646146,
            "end-time": 1585741531483,
            "isStoppable": false,
            "jid": "f140b14e6b02e6538ebadd8bbb55d21b",
            "name": "hz_04011934",
            "now": 1585741531668,
            "plan": {
              "jid": "f140b14e6b02e6538ebadd8bbb55d21b",
              "name": "hz_04011934",
              "nodes": [
                {
                  "description": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -&gt; SourceConversion(table=[default_catalog.default_database.hz_04011934, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -&gt; SinkConversionToRow -&gt; Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                  "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                  "operator": "",
                  "operator_strategy": "",
                  "optimizer_properties": {},
                  "parallelism": 1
                }
              ]
            },
            "start-time": 1585740885337,
            "state": "CANCELED",
            "status-counts": {
              "CANCELED": 1,
              "CANCELING": 0,
              "CREATED": 0,
              "DEPLOYING": 0,
              "FAILED": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RUNNING": 0,
              "SCHEDULED": 0
            },
            "timestamps": {
              "CANCELED": 1585741531483,
              "CANCELLING": 1585741531466,
              "CREATED": 1585740885337,
              "FAILED": 0,
              "FAILING": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RESTARTING": 0,
              "RUNNING": 1585740885475,
              "SUSPENDED": 0
            },
            "vertices": [
              {
                "duration": 645956,
                "end-time": 1585741531482,
                "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                "metrics": {
                  "read-bytes": 0,
                  "read-bytes-complete": true,
                  "read-records": 0,
                  "read-records-complete": true,
                  "write-bytes": 0,
                  "write-bytes-complete": true,
                  "write-records": 0,
                  "write-records-complete": true
                },
                "name": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -> SourceConversion(table=[default_catalog.default_database.hz_04011934, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -> SinkConversionToRow -> Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                "parallelism": 1,
                "start-time": 1585740885526,
                "status": "CANCELED",
                "tasks": {
                  "CANCELED": 1,
                  "CANCELING": 0,
                  "CREATED": 0,
                  "DEPLOYING": 0,
                  "FAILED": 0,
                  "FINISHED": 0,
                  "RECONCILING": 0,
                  "RUNNING": 0,
                  "SCHEDULED": 0
                }
              }
            ]
          }
        },
        "logMeta": {
          "module": "flink-jobmanager-10",
          "namespace": "prophet-resource-huangzhen",
          "query": "f140b14e6b02e6538ebadd8bbb55d21b"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "CANCELED",
        "trackingUrl": "/scoped-flink-cluster/10/history/#/job/f140b14e6b02e6538ebadd8bbb55d21b/overview"
      },
      "id": 4,
      "name": "hz_04011934",
      "sidecarJob": {
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "706ec214-88b3-4d1a-bc77-ed15dc61a03f",
        "info": null,
        "logMeta": {
          "module": "706ec214-88b3-4d1a-bc77-ed15dc61a03f",
          "namespace": "prophet-resource-huangzhen"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "Lost",
        "trackingUrl": "/hdfs-element-scanner/706ec214-88b3-4d1a-bc77-ed15dc61a03f/"
      },
      "status": "CANCELED",
      "updateTime": "Wed, 01 Apr 2020 19:34:45 GMT"
    },
    {
      "config": {
        "createTime": 1585740786000,
        "description": null,
        "entryClass": null,
        "flinkSql": "{\"conf\":{\"delay.interval\":10000,\"checkpoint.cleanup.mode\":false,\"failure.interval\":600000,\"state.backend.incremental\":true,\"sql.ttl.max\":\"10m\",\"failure.rate\":5,\"time.characteristic\":\"ProcessingTime\",\"env.parallelism\":1,\"checkpoint.enable\":true,\"checkpoint.timeout\":600000,\"sql.ttl.min\":\"5m\",\"checkpoint.mode\":\"EXACTLY_ONCE\",\"state.backend\":\"rocksdb\",\"checkpoint.interval\":60000,\"max.concurrent.checkpoints\":1,\"state.checkpoints.dir\":\"hdfs:///tmp\"},\"ddl\":[\"CREATE TABLE `hz_04011932`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04011932')\",\"CREATE TABLE `k2h_hypcml_hz_04011932_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04011932_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\"],\"dml\":[\"insert into k2h_hypcml_hz_04011932_table_group select * from hz_04011932\"],\"name\":\"hz_04011932\"}",
        "id": 9,
        "name": "hz_04011932",
        "owner": "1",
        "ownerName": "4pdadmin",
        "updateTime": 1585740786000,
        "workspaceId": 10
      },
      "createTime": "Wed, 01 Apr 2020 19:33:16 GMT",
      "flinkJob": {
        "config": "{\"id\":9,\"workspaceId\":10,\"owner\":\"1\",\"ownerName\":\"4pdadmin\",\"name\":\"hz_04011932\",\"flinkSql\":\"{\\\"conf\\\":{\\\"delay.interval\\\":10000,\\\"checkpoint.cleanup.mode\\\":false,\\\"failure.interval\\\":600000,\\\"state.backend.incremental\\\":true,\\\"sql.ttl.max\\\":\\\"10m\\\",\\\"failure.rate\\\":5,\\\"time.characteristic\\\":\\\"ProcessingTime\\\",\\\"env.parallelism\\\":1,\\\"checkpoint.enable\\\":true,\\\"checkpoint.timeout\\\":600000,\\\"sql.ttl.min\\\":\\\"5m\\\",\\\"checkpoint.mode\\\":\\\"EXACTLY_ONCE\\\",\\\"state.backend\\\":\\\"rocksdb\\\",\\\"checkpoint.interval\\\":60000,\\\"max.concurrent.checkpoints\\\":1,\\\"state.checkpoints.dir\\\":\\\"hdfs:///tmp\\\"},\\\"ddl\\\":[\\\"CREATE TABLE `hz_04011932`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3)) WITH ('connector.type'='kafka','connector.version'='0.11','connector.topic'='vivo_impression','connector.startup-mode'='latest-offset','connector.properties.zookeeper.connect'='172.27.128.122:6181/shawnkafka11','connector.properties.bootstrap.servers'='172.27.128.122:9393','update-mode'='append','format.type'='json','format.fail-on-missing-field'='false','format.derive-schema'='true','connector.properties.group.id'='hz_04011932')\\\",\\\"CREATE TABLE `k2h_hypcml_hz_04011932_table_group`(`requestId` VARCHAR,`userId` VARCHAR,`itemId` BIGINT,`eventTime` TIMESTAMP(3),WATERMARK FOR `eventTime` AS `eventTime`) WITH ('connector.type'='streamingfile','connector.path'='hdfs:///prophet/ee380_gz/workspace/huangzhen/telamon/1/hypcml/hz_04011932_table-group','connector.format'='parquet','connector.databucketformat'='yyyy-MM-dd-HH','connector.interval'='10','connector.partition'='')\\\"],\\\"dml\\\":[\\\"insert into k2h_hypcml_hz_04011932_table_group select * from hz_04011932\\\"],\\\"name\\\":\\\"hz_04011932\\\"}\",\"createTime\":1585740786000,\"updateTime\":1585740786000}",
        "graphs": [
          {
            "title": "已注册 Task Manager 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=69&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 总数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=67&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "Task Slot 可用数",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=65&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "运行中的 job 数量",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=71&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager live thread",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=42&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          },
          {
            "title": "JobManager Memory Available",
            "url": "http://172.27.128.150:40121/grafana/d-solo/-coPDj9Wz/flink?panelId=5&orgId=1&var-datasource=prometheus&var-wsid=10&theme=light"
          }
        ],
        "id": "1b2fceb14e85f2428d65f5d7bc7e9a7f",
        "info": {
          "checkpoints": {
            "counts": {
              "completed": 2,
              "failed": 0,
              "in_progress": 0,
              "restored": 0,
              "total": 2
            },
            "history": [
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 207,
                "external_path": "hdfs:/tmp/1b2fceb14e85f2428d65f5d7bc7e9a7f/chk-2",
                "id": 2,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585740887991,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585740887784
              },
              {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": true,
                "end_to_end_duration": 579,
                "external_path": "hdfs:/tmp/1b2fceb14e85f2428d65f5d7bc7e9a7f/chk-1",
                "id": 1,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585740828363,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585740827784
              }
            ],
            "latest": {
              "completed": {
                "@class": "completed",
                "alignment_buffered": 0,
                "discarded": false,
                "end_to_end_duration": 207,
                "external_path": "hdfs:/tmp/1b2fceb14e85f2428d65f5d7bc7e9a7f/chk-2",
                "id": 2,
                "is_savepoint": false,
                "latest_ack_timestamp": 1585740887991,
                "num_acknowledged_subtasks": 1,
                "num_subtasks": 1,
                "state_size": 1657,
                "status": "COMPLETED",
                "tasks": {},
                "trigger_timestamp": 1585740887784
              },
              "failed": null,
              "restored": null,
              "savepoint": null
            },
            "summary": {
              "alignment_buffered": {
                "avg": 0,
                "max": 0,
                "min": 0
              },
              "end_to_end_duration": {
                "avg": 393,
                "max": 579,
                "min": 207
              },
              "state_size": {
                "avg": 1657,
                "max": 1657,
                "min": 1657
              }
            }
          },
          "exceptions": {
            "all-exceptions": [],
            "root-exception": null,
            "timestamp": null,
            "truncated": false
          },
          "main": {
            "duration": 109174,
            "end-time": 1585740904727,
            "isStoppable": false,
            "jid": "1b2fceb14e85f2428d65f5d7bc7e9a7f",
            "name": "hz_04011932",
            "now": 1585740905027,
            "plan": {
              "jid": "1b2fceb14e85f2428d65f5d7bc7e9a7f",
              "name": "hz_04011932",
              "nodes": [
                {
                  "description": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -&gt; SourceConversion(table=[default_catalog.default_database.hz_04011932, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -&gt; SinkConversionToRow -&gt; Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                  "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                  "operator": "",
                  "operator_strategy": "",
                  "optimizer_properties": {},
                  "parallelism": 1
                }
              ]
            },
            "start-time": 1585740795553,
            "state": "CANCELED",
            "status-counts": {
              "CANCELED": 1,
              "CANCELING": 0,
              "CREATED": 0,
              "DEPLOYING": 0,
              "FAILED": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RUNNING": 0,
              "SCHEDULED": 0
            },
            "timestamps": {
              "CANCELED": 1585740904727,
              "CANCELLING": 1585740904691,
              "CREATED": 1585740795553,
              "FAILED": 0,
              "FAILING": 0,
              "FINISHED": 0,
              "RECONCILING": 0,
              "RESTARTING": 0,
              "RUNNING": 1585740795962,
              "SUSPENDED": 0
            },
            "vertices": [
              {
                "duration": 98960,
                "end-time": 1585740904723,
                "id": "cbc357ccb763df2852fee8c4fc7d55f2",
                "metrics": {
                  "read-bytes": 0,
                  "read-bytes-complete": true,
                  "read-records": 0,
                  "read-records-complete": true,
                  "write-bytes": 0,
                  "write-bytes-complete": true,
                  "write-records": 0,
                  "write-records-complete": true
                },
                "name": "Source: Kafka011TableSource(requestId, userId, itemId, eventTime) -> SourceConversion(table=[default_catalog.default_database.hz_04011932, source: [Kafka011TableSource(requestId, userId, itemId, eventTime)]], fields=[requestId, userId, itemId, eventTime]) -> SinkConversionToRow -> Sink: StreamingFileTableSink(requestId, userId, itemId, eventTime)",
                "parallelism": 1,
                "start-time": 1585740805763,
                "status": "CANCELED",
                "tasks": {
                  "CANCELED": 1,
                  "CANCELING": 0,
                  "CREATED": 0,
                  "DEPLOYING": 0,
                  "FAILED": 0,
                  "FINISHED": 0,
                  "RECONCILING": 0,
                  "RUNNING": 0,
                  "SCHEDULED": 0
                }
              }
            ]
          }
        },
        "logMeta": {
          "module": "flink-jobmanager-10",
          "namespace": "prophet-resource-huangzhen",
          "query": "1b2fceb14e85f2428d65f5d7bc7e9a7f"
        },
        "monitorUrl": "http://172.27.128.150:40121/monitor-center/#/alert_rules",
        "rootException": null,
        "status": "CANCELED",
        "trackingUrl": "/scoped-flink-cluster/10/history/#/job/1b2fceb14e85f2428d65f5d7bc7e9a7f/overview"
      },
      "id": 3,
      "name": "hz_04011932",
      "status": "CANCELED",
      "updateTime": "Wed, 01 Apr 2020 19:33:16 GMT"
    }
  ]
}